/**
* OpenAPI Petstore
* This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
*
* OpenAPI spec version: 1.0.0
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/
/*
 * User.h
 *
 * A User who is purchasing from the pet store
 */

#ifndef User_H_
#define User_H_


#include "ModelBase.h"

#include <string>

namespace org {
namespace openapitools {
namespace server {
namespace model {

/// <summary>
/// A User who is purchasing from the pet store
/// </summary>
class  User
    : public ModelBase
{
public:
    User();
    virtual ~User();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// User members

    /// <summary>
    /// 
    /// </summary>
    int64_t getId() const;
    void setId(int64_t value);
    bool idIsSet() const;
    void unsetId();
    /// <summary>
    /// 
    /// </summary>
    std::string getUsername() const;
    void setUsername(std::string value);
    bool usernameIsSet() const;
    void unsetUsername();
    /// <summary>
    /// 
    /// </summary>
    std::string getFirstName() const;
    void setFirstName(std::string value);
    bool firstNameIsSet() const;
    void unsetFirstName();
    /// <summary>
    /// 
    /// </summary>
    std::string getLastName() const;
    void setLastName(std::string value);
    bool lastNameIsSet() const;
    void unsetLastName();
    /// <summary>
    /// 
    /// </summary>
    std::string getEmail() const;
    void setEmail(std::string value);
    bool emailIsSet() const;
    void unsetEmail();
    /// <summary>
    /// 
    /// </summary>
    std::string getPassword() const;
    void setPassword(std::string value);
    bool passwordIsSet() const;
    void unsetPassword();
    /// <summary>
    /// 
    /// </summary>
    std::string getPhone() const;
    void setPhone(std::string value);
    bool phoneIsSet() const;
    void unsetPhone();
    /// <summary>
    /// User Status
    /// </summary>
    int32_t getUserStatus() const;
    void setUserStatus(int32_t value);
    bool userStatusIsSet() const;
    void unsetUserStatus();

protected:
    int64_t m_Id;
    bool m_IdIsSet;
    std::string m_Username;
    bool m_UsernameIsSet;
    std::string m_FirstName;
    bool m_FirstNameIsSet;
    std::string m_LastName;
    bool m_LastNameIsSet;
    std::string m_Email;
    bool m_EmailIsSet;
    std::string m_Password;
    bool m_PasswordIsSet;
    std::string m_Phone;
    bool m_PhoneIsSet;
    int32_t m_UserStatus;
    bool m_UserStatusIsSet;
};

}
}
}
}

#endif /* User_H_ */