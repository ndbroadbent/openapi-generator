#!/bin/sh

SCRIPT="$0"
echo "# START SCRIPT: $SCRIPT"

while [ -h "$SCRIPT" ] ; do
  ls=`ls -ld "$SCRIPT"`
  link=`expr "$ls" : '.*-> \(.*\)$'`
  if expr "$link" : '/.*' > /dev/null; then
    SCRIPT="$link"
  else
    SCRIPT=`dirname "$SCRIPT"`/"$link"
  fi
done

if [ ! -d "${APP_DIR}" ]; then
  APP_DIR=`dirname "$SCRIPT"`/..
  APP_DIR=`cd "${APP_DIR}"; pwd`
fi

executable="./modules/openapi-generator-cli/target/openapi-generator-cli.jar"

if [ ! -f "$executable" ]
then
  mvn -B clean package
fi

# if you've executed sbt assembly previously it will use that instead.
export JAVA_OPTS="${JAVA_OPTS} -XX:MaxPermSize=256M -Xmx1024M -DloggerPath=conf/log4j.properties"

# Generate non-browserClient
ags="generate -t modules/openapi-generator/src/main/resources/dart -i modules/openapi-generator/src/test/resources/2_0/petstore.yaml -g dart -o samples/client/petstore/dart2/openapi -DhideGenerationTimestamp=true -DbrowserClient=false --additional-properties supportDart2=true $@"

# then options to generate the library for vm would be:
#ags="generate -i modules/openapi-generator/src/test/resources/2_0/petstore.yaml -g dart -o samples/client/petstore/dart2/openapi_vm -DbrowserClient=false -DpubName=openapi_vm $@"
java $JAVA_OPTS -jar $executable $ags

# Generate browserClient
ags="generate -t modules/openapi-generator/src/main/resources/dart -i modules/openapi-generator/src/test/resources/2_0/petstore.yaml -g dart -o samples/client/petstore/dart2/openapi-browser-client -DhideGenerationTimestamp=true -DbrowserClient=true --additional-properties supportDart2=true $@"
java $JAVA_OPTS -jar $executable $ags

# Generate non-browserClient and put it to the flutter sample app
ags="generate -t modules/openapi-generator/src/main/resources/dart -i modules/openapi-generator/src/test/resources/2_0/petstore.yaml -g dart -o samples/client/petstore/dart2/flutter_petstore/openapi -DhideGenerationTimestamp=true -DbrowserClient=false --additional-properties supportDart2=true $@"
java $JAVA_OPTS -jar $executable $ags

# There is a proposal to allow importing different libraries depending on the environment:
# https://github.com/munificent/dep-interface-libraries
# When this is implemented there will only be one library.

# The current petstore test will then work for both: the browser library and the vm library.
