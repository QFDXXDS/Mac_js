/** 
{file:
	{name: VidyoUser.h}
	{description: User Entity Library. }
	{copyright:
		(c) 2013-2016 Vidyo, Inc.,
		433 Hackensack Avenue,
		Hackensack, NJ  07601.
		All rights reserved.
		The information contained herein is proprietary to Vidyo, Inc.
		and shall not be reproduced, copied (in whole or in part), adapted,
		modified, disseminated, transmitted, transcribed, stored in a retrieval
		system, or translated into any language in any form by any means
		without the express written consent of Vidyo, Inc.}
}
*/
#ifndef VIDYO_USER_H_ 
#define VIDYO_USER_H_ 

#include <Lmi/Os/LmiLog.h>
#include <Lmi/Os/LmiSharedPtr.h>
#include <Lmi/Utils/LmiUri.h>
#include <Lmi/Utils/LmiList.h>

LMI_BEGIN_EXTERN_C
struct VidyoUserImpl_;
typedef struct VidyoUserImpl_ VidyoUserImpl;
Declare_LmiSharedPtr(VidyoUserImpl)
Declare_LmiSharedPtrWrapper(VidyoUser, VidyoUserImpl)
Declare_LmiWeakPtrWrapper(VidyoUserHandle, VidyoUser, VidyoUserImpl)
Declare_LmiList(VidyoUser)
Declare_LmiList(VidyoUserHandle)

LMI_END_EXTERN_C

#include "VidyoEventSchedule.h"
#include "VidyoTransport.h"
#include "VidyoCodec.h"
#include "VidyoEndpoint.h"
#include "VidyoRoom.h"
#include "VidyoCall.h"
#include "VidyoContactInfo.h"
#include "VidyoContact.h"
#include "VidyoRoomInfo.h"
#include "VidyoRoomProperties.h"

LMI_BEGIN_EXTERN_C

/**
{type apigroup="simple" visibility="public":
	{name: VidyoUserLoginResult}
	{parent: VidyoUser}
	{description: This type indicates the result of an attempt to log in to some service.}
	{value: {name: VIDYO_USERLOGINRESULT_OK}
		{description: The user logged in successfully.}}
	{value: {name: VIDYO_USERLOGINRESULT_ConnectionFailed}
		{description: The destination could not be reached.}}
	{value: {name: VIDYO_USERLOGINRESULT_ConnectionLost}
		{description: The transport connection was lost prior to completing the login procedure.}}
 	{value: {name: VIDYO_USERLOGINRESULT_ConnectionTimeout}
		{description: The signaling connection timed out prior to completing the login procedure.}}
	{value: {name: VIDYO_USERLOGINRESULT_NoResponse}
		{description: The service was successfully contacted, but the service ignored the user's
			request to log in, or did not answer in a reasonable amount of time.}}
	{value: {name: VIDYO_USERLOGINRESULT_Terminated}
		{description: The service was successfully contacted, but the service closed the connection
			or refused to continue processing the login request.}}
	{value: {name: VIDYO_USERLOGINRESULT_InvalidUser}
		{description: The user ID that was provided is unknown to the service or unauthorized to log in.}}
	{value: {name: VIDYO_USERLOGINRESULT_InvalidPassword}
		{description: The password that was provided is incorrect.}}
	{value: {name: VIDYO_USERLOGINRESULT_MiscAuthError}
		{description: The login failed for some other authentication error.}}
	{value: {name: VIDYO_USERLOGINRESULT_Cancelled}
		{description: The user cancelled the login request before it completed.}}
	{value: {name: VIDYO_USERLOGINRESULT_MiscError}
		{description: The login failed for some other miscellaneous error.}}
	{value: {name: VIDYO_USERLOGINRESULT_WebProxyAuthenticationRequired}
		{description: The login failed as the web proxy address required authentication.}}
    {value: {name: VIDYO_USERLOGINRESULT_ServiceUnavailable}
        {description: The login failed as the service is not available.}}
    {value: {name: VIDYO_USERLOGINRESULT_RoomIsFull}
        {description: The login with room key failed as the room is full.}}
    {value: {name: VIDYO_USERLOGINRESULT_RoomIsDisabled}
        {description: The login with room key failed as the room is disabled.}}
	{value: {name: VIDYO_USERLOGINRESULT_TlsFailed}
		{description: The login failed as TLS negotiation failed.}}
	{value: {name: VIDYO_USERLOGINRESULT_CertificateVerificationFailed}
		{description: The login failed as the client certificate verification has failed.}}
    {value: {name: VIDYO_USERLOGINRESULT_UnsupportedTenantVersion}
        {description: The login failed as the tenant/backend is of an unsupported version.}}
	{value: {name: VIDYO_USERLOGINRESULT_NoValidNetworkInterface}
		{description: The login failed as there is no valid network interface available.}}
}
*/
typedef enum
{
	VIDYO_USERLOGINRESULT_OK,
	VIDYO_USERLOGINRESULT_ConnectionFailed,
	VIDYO_USERLOGINRESULT_ConnectionLost,
	VIDYO_USERLOGINRESULT_ConnectionTimeout,
	VIDYO_USERLOGINRESULT_NoResponse,
	VIDYO_USERLOGINRESULT_Terminated,
	VIDYO_USERLOGINRESULT_InvalidUser,
	VIDYO_USERLOGINRESULT_InvalidPassword,
	VIDYO_USERLOGINRESULT_MiscAuthError,
	VIDYO_USERLOGINRESULT_Cancelled,
	VIDYO_USERLOGINRESULT_MiscError,
	VIDYO_USERLOGINRESULT_WebProxyAuthenticationRequired,
    VIDYO_USERLOGINRESULT_ServiceUnavailable,
    VIDYO_USERLOGINRESULT_RoomIsFull,
    VIDYO_USERLOGINRESULT_RoomIsDisabled,
	VIDYO_USERLOGINRESULT_TlsFailed,
	VIDYO_USERLOGINRESULT_CertificateVerificationFailed,
    VIDYO_USERLOGINRESULT_UnsupportedTenantVersion,
	VIDYO_USERLOGINRESULT_NoValidNetworkInterface,
} VidyoUserLoginResult;

/**
{type apigroup="simple" visibility="public":
	{name: VidyoUserLogoutReason}
	{parent: VidyoUser}
	{description: This type indicates the reason that a user that was once logged in is no longer logged in.}
	{value: {name: VIDYO_USERLOGOUTREASON_LoggedOut}
		{description: The user logged out gracefully.}}
	{value: {name: VIDYO_USERLOGOUTREASON_ConnectionLost}
		{description: The transport connection was lost.}}
 	{value: {name: VIDYO_USERLOGOUTREASON_ConnectionTimeout}
		{description: The signaling connection timed out.}}
	{value: {name: VIDYO_USERLOGOUTREASON_NoResponse}
		{description: The service did not respond in a reasonable amount of time to a request by the user.}}
	{value: {name: VIDYO_USERLOGOUTREASON_Terminated}
		{description: The service closed the connection or otherwise terminated the login session.}}
	{value: {name: VIDYO_USERLOGOUTREASON_MiscError}
		{description: The login session was closed for some other miscellaneous reason.}}
	{value: {name: VIDYO_USERLOGOUTREASON_LoggedInElsewhere}
		{description: The same user has logged in from somewhere else.}}
	{value: {name: VIDYO_USERLOGOUTREASON_NetworkInterfaceChanged}
		{description: The network interface changed.}}
	{value: {name: VIDYO_USERLOGOUTREASON_OutOfLicenses}
		{description: The Portal is out of licenses.}}
	{value: {name: VIDYO_USERLOGOUTREASON_EpClientBadConnection}
		{description: Logged out due to bad connection with VidyoManager.}}
	{value: {name: VIDYO_USERLOGOUTREASON_EpClientBadVersion}
		{description: Logged out as VidyoManager rejected the connection as EMCP version is bad.}}
	{value: {name: VIDYO_USERLOGOUTREASON_EpClientBadSessionId}
		{description: Logged out as the Endpoint's session ID did not match that of the VidyoManager.}}
	{value: {name: VIDYO_USERLOGOUTREASON_EpClientBadComms}
		{description: Logged out due to Bad communication with VidyoManager.EpClient can no longer insure proper operation.}}
	{value: {name: VIDYO_USERLOGOUTREASON_EpClientRebootRequested}
		{description: Logged out as the VidyoManager has requested that the Endpoint reset.}}
	{value: {name: VIDYO_USERLOGOUTREASON_EpClientShutdownRequested}
		{description: Logged out as the VidyoManager has requested that the Endpoint reset.}}
	{value: {name: VIDYO_USERLOGOUTREASON_EpClientRestartRequested}
		{description: Logged out as the VidyoManager has requested that the Endpoint reset.}}
	{value: {name: VIDYO_USERLOGOUTREASON_EpClientInternalError}
		{description: Logged out because an internal error occurred at the epclient.}}
	{value: {name: VIDYO_USERLOGOUTREASON_EndpointNotBound}
		{description: Logged out as the endpoint is not bound to the backend and will not be able join calls.}}
	{value: {name: VIDYO_USERLOGOUTREASON_InvalidAuth}
		{description: Logged out as the authentication is no longer valid.}}
    {value: {name: VIDYO_USERLOGOUTREASON_EpClientStartFailure}
        {description: Logged out as we failed to start EpClient}}
}
*/
typedef enum
{
	VIDYO_USERLOGOUTREASON_LoggedOut,
	VIDYO_USERLOGOUTREASON_ConnectionLost,
	VIDYO_USERLOGOUTREASON_ConnectionTimeout,
	VIDYO_USERLOGOUTREASON_NoResponse,
	VIDYO_USERLOGOUTREASON_Terminated,
	VIDYO_USERLOGOUTREASON_MiscError,
	VIDYO_USERLOGOUTREASON_LoggedInElsewhere,
	VIDYO_USERLOGOUTREASON_NetworkInterfaceChanged,
	VIDYO_USERLOGOUTREASON_OutOfLicenses,
	VIDYO_USERLOGOUTREASON_EpClientBadConnection,
	VIDYO_USERLOGOUTREASON_EpClientBadVersion,
	VIDYO_USERLOGOUTREASON_EpClientBadSessionId,
	VIDYO_USERLOGOUTREASON_EpClientBadComms,
	VIDYO_USERLOGOUTREASON_EpClientRebootRequested,
	VIDYO_USERLOGOUTREASON_EpClientShutdownRequested,
	VIDYO_USERLOGOUTREASON_EpClientRestartRequested,
	VIDYO_USERLOGOUTREASON_EpClientInternalError,
	VIDYO_USERLOGOUTREASON_EndpointNotBound,
	VIDYO_USERLOGOUTREASON_InvalidAuth,
    VIDYO_USERLOGOUTREASON_EpClientStartFailure
} VidyoUserLogoutReason;

/**
{type apigroup="simple" visibility="public":
	{name: VidyoUserAuthType}
	{parent: VidyoUser}
	{description: This type indicates the authentication type that needs to be used by the user to login.}
	{value: {name: VIDYO_USERAUTHTYPE_Guest}
		{description: Guest authnetication can be used to login.}}
	{value: {name: VIDYO_USERAUTHTYPE_Password}
		{description: Password can be used to login.}}
	{value: {name: VIDYO_USERAUTHTYPE_AccessToken}
		{description: AccessToken can be used to login.}}
	{value: {name: VIDYO_USERAUTHTYPE_RefreshToken}
		{description: RefreshToken can be used to login.}}
	{value: {name: VIDYO_USERAUTHTYPE_ProvisionToken}
		{description: ProvisionToken can be used to login.}}
	{value: {name: VIDYO_USERAUTHTYPE_Facebook}
		{description: Facebook authnetication can be used to login.}}
	{value: {name: VIDYO_USERAUTHTYPE_Saml}
		{description: SAML authnetication can be used to login.}}
	{value: {name: VIDYO_USERAUTHTYPE_Cac}
		{description: CAC authnetication can be used to login.}}
	{note: The only valid auth Types for PortalService are VIDYO_USERAUTHTYPE_Password, VIDYO_USERAUTHTYPE_Saml and VIDYO_USERAUTHTYPE_Cac}
}
*/

typedef enum VidyoUserAuthType_
{
	VIDYO_USERAUTHTYPE_Guest,
	VIDYO_USERAUTHTYPE_Password,
	VIDYO_USERAUTHTYPE_AccessToken,
	VIDYO_USERAUTHTYPE_RefreshToken,
	VIDYO_USERAUTHTYPE_ProvisionToken,
	VIDYO_USERAUTHTYPE_Facebook,
	VIDYO_USERAUTHTYPE_GuestWithRoomKey,
	VIDYO_USERAUTHTYPE_Saml,
	VIDYO_USERAUTHTYPE_Cac,
} VidyoUserAuthType;

Declare_LmiBasicType(VidyoUserAuthType)
Declare_LmiVector(VidyoUserAuthType)

/**
 {type visibility="public":
 	{name: VidyoUserAuthenticationInfo}
 	{parent: VidyoUser}
 	{description: Represents the authentication information the server supported.}
 	{member:
 		{name: authType}
		{type: VidyoUserAuthType}
 		{description: }
 	}
 	{member:
 		{name: property}
 		{type: VidyoProperty}
 		{description: }
 	}
 }
 */
typedef struct {
	VidyoUserAuthType authType;
	VidyoProperty property;
} VidyoUserAuthenticationInfo;

VidyoUserAuthenticationInfo* VidyoUserAuthenticationInfoConstructDefault(VidyoUserAuthenticationInfo* authInfo, LmiAllocator* alloc);

LMI_INLINE_DECLARATION void VidyoUserAuthenticationInfoDestruct(VidyoUserAuthenticationInfo* authInfo);


LMI_INLINE_DECLARATION VidyoUserAuthenticationInfo* VidyoUserAuthenticationInfoConstructCopy(VidyoUserAuthenticationInfo* a, const VidyoUserAuthenticationInfo* o);
LMI_INLINE_DECLARATION VidyoUserAuthenticationInfo* VidyoUserAuthenticationInfoAssign(VidyoUserAuthenticationInfo* a, const VidyoUserAuthenticationInfo* o);
LMI_INLINE_DECLARATION LmiBool VidyoUserAuthenticationInfoEqual(const VidyoUserAuthenticationInfo* a, const VidyoUserAuthenticationInfo* o);
LMI_INLINE_DECLARATION LmiBool VidyoUserAuthenticationInfoLess(const VidyoUserAuthenticationInfo* a, const VidyoUserAuthenticationInfo* o);
Declare_LmiVector(VidyoUserAuthenticationInfo)

/**
{type apigroup="simple" visibility="public":
	{name: VidyoUserTokenType}
	{parent: VidyoUser}
	{description: An enumeration of authentication key types.}
	{value: {name: VIDYO_USERTOKENTYPE_RefreshToken} {description: The associated key is a refresh token.}}
	{value: {name: VIDYO_USERTOKENTYPE_AccessToken} {description: The associated key is an access token.}}
}
*/
typedef enum {
	VIDYO_USERTOKENTYPE_RefreshToken,
	VIDYO_USERTOKENTYPE_AccessToken
} VidyoUserTokenType;

/**
{type apigroup="simple" visibility="public":
	{name: VidyoUserSearchResult}
	{parent: VidyoUser}
	{description: This type indicates the result of a search for user or room.}
	{value: {name: VIDYO_USERSEARCHRESULT_OK} {description: The search operation was
		successful.}}
	{value: {name: VIDYO_USERSEARCHRESULT_NoRecords} {description: No records found
		for the search.}}
	{value: {name: VIDYO_USERSEARCHRESULT_NoResponse} {description: The search
		result failed due to request timeout.}}
	{value: {name: VIDYO_USERSEARCHRESULT_MiscLocalError} {description: The search
		result failed due to some miscellaneous local problem.}}
	{value: {name: VIDYO_USERSEARCHRESULT_MiscRemoteError} {description: The search
		result failed due to some miscellaneous remote problem.}}
}
*/
typedef enum
{
	VIDYO_USERSEARCHRESULT_OK,
	VIDYO_USERSEARCHRESULT_NoRecords,
	VIDYO_USERSEARCHRESULT_NoResponse,
	VIDYO_USERSEARCHRESULT_MiscLocalError,
	VIDYO_USERSEARCHRESULT_MiscRemoteError
} VidyoUserSearchResult;

/**
{type apigroup="simple" visibility="public":
	{name: VidyoUserGetContactResult}
	{parent: VidyoUser}
	{description: This type indicates the result of getting a contact vCard.}
	{value: {name: VIDYO_USERGETCONTACTRESULT_OK} {description: The request was successful.}}
	{value: {name: VIDYO_USERGETCONTACTRESULT_NoResponse} {description: The server did
		not respond in a reasonable amount of time.}}
	{value: {name: VIDYO_USERGETCONTACTRESULT_Unauthorized} {description: The user is
		not allowed to get contacts.}}
	{value: {name: VIDYO_USERGETCONTACTRESULT_MiscLocalError} {description: The server is
		rejecting the request due to some miscellaneous problem with the request.}}
	{value: {name: VIDYO_USERGETCONTACTRESULT_MiscRemoteError} {description: The server is
		rejecting the request due to some miscellaneous problem of its own.}}
}
*/
typedef enum
{
	VIDYO_USERGETCONTACTRESULT_OK,
	VIDYO_USERGETCONTACTRESULT_NoResponse,
	VIDYO_USERGETCONTACTRESULT_Unauthorized,
	VIDYO_USERGETCONTACTRESULT_MiscLocalError,
	VIDYO_USERGETCONTACTRESULT_MiscRemoteError
} VidyoUserGetContactResult;

/**

{type visibility="public":
	{name: VidyoUserCallCreateResult}
	{parent: VidyoUser}
	{description: This type indicates the result of an attempt to create call.}
	{value: {name: VIDYO_USERCALLCREATERESULT_OK} {description: The call created successfully.}}
	{value: {name: VIDYO_USERCALLCREATERESULT_NoResponse} {description: The server did
		not respond in a reasonable amount of time to the request to create the call.}}
	{value: {name: VIDYO_USERCALLCREATERESULT_NotAllowed} {description: The user is
		not allowed to create call.}}
	{value: {name: VIDYO_USERCALLCREATERESULT_MiscLocalError} {description: The server is
		rejecting the request to create the call due to some miscellaneous problem with the request.}}
	{value: {name: VIDYO_USERCALLCREATERESULT_MiscRemoteError} {description: The server is
		rejecting the request to create the call due to some miscellaneous problem of its own.}}
}
*/
typedef enum
{
	VIDYO_USERCALLCREATERESULT_OK,
	VIDYO_USERCALLCREATERESULT_NoResponse,
	VIDYO_USERCALLCREATERESULT_NotAllowed,
	VIDYO_USERCALLCREATERESULT_MiscLocalError,
	VIDYO_USERCALLCREATERESULT_MiscRemoteError
} VidyoUserCallCreateResult;


/**
{type apigroup="simple" visibility="public":
	{name: VidyoUserRoomCreateResult}
	{parent: VidyoUser}
	{description: This type indicates the result of an attempt to create room.}
	{value: {name: VIDYO_USERROOMCREATERESULT_OK} {description: The room entered successfully.}}
	{value: {name: VIDYO_USERROOMCREATERESULT_NoResponse} {description: The server did
		not respond in a reasonable amount of time to the request to enter the room.}}
	{value: {name: VIDYO_USERROOMCREATERESULT_NotFound} {description: The server did
		not find the room.}}
	{value: {name: VIDYO_USERROOMCREATERESULT_Unauthorized} {description: The user is
		not allowed to create rooms.}}
	{value: {name: VIDYO_USERROOMCREATERESULT_MiscLocalError} {description: The server is
		rejecting the request to enter due to some miscellaneous problem with the request.}}
	{value: {name: VIDYO_USERROOMCREATERESULT_MiscRemoteError} {description: The server is
		rejecting the request to enter due to some miscellaneous problem of its own.}}
	{value: {name: VIDYO_USERROOMCREATERESULT_DuplicateName} {description: The room
		with this name already exists.}}
	{value: {name: VIDYO_USERROOMCREATERESULT_LimitReached} {description: THe user has already
		created max number of rooms allowd by the server.}}
	{value: {name: VIDYO_USERROOMCREATERESULT_NotSupported} {description: The server does not support room creation.}}
}
*/
typedef enum
{
	VIDYO_USERROOMCREATERESULT_OK,
	VIDYO_USERROOMCREATERESULT_NoResponse,
	VIDYO_USERROOMCREATERESULT_NotFound,
	VIDYO_USERROOMCREATERESULT_Unauthorized,
	VIDYO_USERROOMCREATERESULT_MiscLocalError,
	VIDYO_USERROOMCREATERESULT_MiscRemoteError,
	VIDYO_USERROOMCREATERESULT_DuplicateName,
	VIDYO_USERROOMCREATERESULT_LimitReached,
	VIDYO_USERROOMCREATERESULT_NotSupported,
} VidyoUserRoomCreateResult;

/**
{type apigroup="simple" visibility="public":
{name: VidyoUserConnectionStatusChangedReason}
{parent: VidyoUser}
{description: This type indicates the reason for a change in connection status .}
{value: {name: VIDYO_USERCONNECTIONSTATUSCHANGEDREASON_OK} {description: Connected to the server}}
{value: {name: VIDYO_USERCONNECTIONSTATUSCHANGEDREASON_LostContactWithServer} {description: Lost contact with the server}}
{value: {name: VIDYO_USERCONNECTIONSTATUSCHANGEDREASON_NoCommunicationWithServer} {description: No communication with the server}}
{value: {name: VIDYO_USERCONNECTIONSTATUSCHANGEDREASON_NoValidNetworkInterfaces} {description: The user has no valid network interfaces available.}}
{value: {name: VIDYO_USERCONNECTIONSTATUSCHANGEDREASON_NetworkInterfaceChanged} {description: The user's network interfaces have changed. }}
{value: {name: VIDYO_USERCONNECTIONSTATUSCHANGEDREASON_MiscNetworkError} {description: Misc network error }}
{value: {name: VIDYO_USERCONNECTIONSTATUSCHANGEDREASON_ConnectionError} {description: Error on connecting to backend.}}
}
*/
typedef enum
{
	VIDYO_USERCONNECTIONSTATUSCHANGEDREASON_OK,
	VIDYO_USERCONNECTIONSTATUSCHANGEDREASON_LostContactWithServer,
	VIDYO_USERCONNECTIONSTATUSCHANGEDREASON_NoCommunicationWithServer,
	VIDYO_USERCONNECTIONSTATUSCHANGEDREASON_NoValidNetworkInterfaces,
	VIDYO_USERCONNECTIONSTATUSCHANGEDREASON_NetworkInterfaceChanged,
	VIDYO_USERCONNECTIONSTATUSCHANGEDREASON_MiscNetworkError,
	VIDYO_USERCONNECTIONSTATUSCHANGEDREASON_ConnectionError,
} VidyoUserConnectionStatusChangedReason;

/**
{type visibility="public":
	{name: VidyoUserSearchField}
	{parent: VidyoUser}
	{description: This type specify the user details to search.}
	{value: {name: VIDYO_USERSEARCHFIELD_UID} {description: id of the user.}}
	{value: {name: VIDYO_USERSEARCHFIELD_EMAIL} {description: mail of the user.}}
	{value: {name: VIDYO_USERSEARCHFIELD_NAME} {description: display name of the user.}}
	{value: {name: VIDYO_USERSEARCHFIELD_TELNO} {description: telephone number of user.}}
}
*/
typedef enum {
	VIDYO_USERSEARCHFIELD_UID = 0,
	VIDYO_USERSEARCHFIELD_EMAIL,
	VIDYO_USERSEARCHFIELD_NAME,
	VIDYO_USERSEARCHFIELD_TELNO
}VidyoUserSearchField;

/**
{type visibility="public":
	{name: VidyoRoomSearchField}
	{parent: VidyoUser}
	{description: This type specify the room property to search.}
	{value: {name: VIDYO_ROOMSEARCHFIELD_Owner} {description: owner of the rom.}}
	{value: {name: VIDYO_ROOMSEARCHFIELD_Admin} {description: administrator of the room.}}
	{value: {name: VIDYO_ROOMSEARCHFIELD_Moderator} {description: moderator of the room.}}
	{value: {name: VIDYO_ROOMSEARCHFIELD_Member} {description: member of the room.}}
	{value: {name: VIDYO_ROOMSEARCHFIELD_User} {description: user of the room.}}
	{value: {name: VIDYO_ROOMSEARCHFIELD_Name} {description: name of the room.}}
	{value: {name: VIDYO_ROOMSEARCHFIELD_Subject} {description: subject of the room.}}
	{value: {name: VIDYO_ROOMSEARCHFIELD_Type} {description: type of the room.}}
	{value: {name: VIDYO_ROOMSEARCHFIELD_Public} {description: visibility of the room; value of "true" indicates public room.}}
	{value: {name: VIDYO_ROOMSEARCHFIELD_NonMembers} {description: number of members in the room includes owners, admins, moderators and members.}}
}
*/
typedef enum {
	VIDYO_ROOMSEARCHFIELD_Owner = 0,
	VIDYO_ROOMSEARCHFIELD_Admin,
	VIDYO_ROOMSEARCHFIELD_Moderator,
	VIDYO_ROOMSEARCHFIELD_Member,
	VIDYO_ROOMSEARCHFIELD_User,
	VIDYO_ROOMSEARCHFIELD_Name,
	VIDYO_ROOMSEARCHFIELD_Subject,
	VIDYO_ROOMSEARCHFIELD_Type,
	VIDYO_ROOMSEARCHFIELD_Public,
	VIDYO_ROOMSEARCHFIELD_NonMembers
}VidyoRoomSearchField;


/**
{type visibility="public":
	{name: VidyoRoomSearchFieldRelation}
	{parent: VidyoUser}
	{description: This type specify the relation between room property fields that apply in the search, AND operator gets evaluated before OR.}
	{value: {name: VIDYO_ROOMSEARCHFIELDRELATION_AND} {description: apply logical AND between the fields.}}
	{value: {name: VIDYO_ROOMSEARCHFIELDRELATION_OR} {description: apply logical OR between the fields.}}
}
*/
typedef enum {
	VIDYO_ROOMSEARCHFIELDRELATION_AND = 1,
	VIDYO_ROOMSEARCHFIELDRELATION_OR = 0
}VidyoRoomSearchFieldRelation;


/**
{type apigroup="simple" reference-counted="yes":
	{name: VidyoUser}
	{parent: Endpoint}
	{description: }
}
*/

/**
{type visibility="private":
	{name: VidyoUserHandle}
	{parent: VidyoUser}
	{description: }
}
*/

/**
 {type visibility="public":
 	{name: VidyoUserLoginInfo}
 	{parent: VidyoUser}
 	{description: Represents the login attempt information fro the user.}
	{member:
 		{name: result}
 		{type: LmiString}
 		{description: indicates wether the login attempt was sucessful or a failure.}
 	}
 	{member:
 		{name: sourceIp}
 		{type: LmiString}
 		{description: The ip address from which the login was initiated}
 	}
 	{member:
 		{name: timestamp}
 		{type: LmiString}
 		{description: The time at which the login was initiated}
 	}
 }
 */

typedef struct VidyoUserLoginInfo_
{
	LmiString result;
	LmiString sourceIp;
	LmiString timestamp;
} VidyoUserLoginInfo;

/**
 {function visibility="private":
 	{name: VidyoUserLoginInfoConstructDefault}
 	{parent: VidyoUserLoginInfo}
 	{description: Constructs an VidyoUserLoginInfo object.}
 	{prototype: VidyoUserLoginInfo *VidyoUserLoginInfoConstructDefault(VidyoUserLoginInfo *p, LmiAllocator *alloc)}
 	{parameter: {name: p} {description: The VidyoUserLoginInfo object to construct.}}
 	{parameter: {name: alloc} {description: An allocator to use for miscellaneous items.}}
 	{return: A pointer to a constructed object on success, or NULL on failure.}
 }
 */
VidyoUserLoginInfo *VidyoUserLoginInfoConstructDefault(VidyoUserLoginInfo *p, LmiAllocator *alloc);

/**
 {function visibility="private":
 	{name: VidyoUserLoginInfoConstructCopy}
 	{parent: VidyoUserLoginInfo}
 	{description: Constructs an VidyoUserLoginInfo object as a copy of an existing object.}
 	{prototype: VidyoUserLoginInfo *VidyoUserLoginInfoConstructCopy(VidyoUserLoginInfo *d, const VidyoUserLoginInfo *s)}
 	{parameter: {name: d} {description: The VidyoUserLoginInfo object to construct.}}
 	{parameter: {name: s} {description: The existing VidyoUserLoginInfo object to copy.}}
 	{return: A pointer to a constructed object on success, or NULL on failure.}
 }
 */
VidyoUserLoginInfo *VidyoUserLoginInfoConstructCopy(VidyoUserLoginInfo *d, const VidyoUserLoginInfo *s);

/**
 {function visibility="private":
 	{name: VidyoUserLoginInfoDestruct}
 	{parent: VidyoUserLoginInfo}
 	{description: Destructs an VidyoUserLoginInfo object.}
 	{prototype: void VidyoUserLoginInfoDestruct(VidyoUserLoginInfo *p)}
 	{parameter: {name: p} {description: The VidyoUserLoginInfo object to destruct.}}
 }
 */
void VidyoUserLoginInfoDestruct(VidyoUserLoginInfo *p);

/**
 {function visibility="private":
 	{name: VidyoUserLoginInfoAssign}
 	{parent: VidyoUserLoginInfo}
 	{description: Assign the contents of one VidyoUserLoginInfo to another.}
 	{prototype: VidyoUserLoginInfo *VidyoUserLoginInfoAssign(VidyoUserLoginInfo *d, const VidyoUserLoginInfo *s)}
 	{parameter: {name: d} {description: The object to assign to.}}
 	{parameter: {name: s} {description: The object to copy.}}
 	{return: A pointer to the assigned object on success, or NULL on failure.}
 }
 */
VidyoUserLoginInfo *VidyoUserLoginInfoAssign(VidyoUserLoginInfo *d, const VidyoUserLoginInfo *s);

/**
 {function visibility="private":
 	{name: VidyoUserLoginInfoEqual}
 	{parent: VidyoUserLoginInfo}
 	{description: Check the equality of VidyoUserLoginInfo object.}
 	{prototype: LmiBool VidyoUserLoginInfoEqual(const VidyoUserLoginInfo *a, const VidyoUserLoginInfo *b)}
 	{parameter: {name: a} {description: The VidyoUserLoginInfo object to compare.}}
 	{parameter: {name: b} {description: The VidyoUserLoginInfo object to compare.}}
 	{return: LMI_TRUE if equal LMI_FALSE otherwise.}
 }
 */
LmiBool VidyoUserLoginInfoEqual(const VidyoUserLoginInfo *a, const VidyoUserLoginInfo *b);
Declare_LmiVector(VidyoUserLoginInfo)

/**
 {type visibility="public":
 	{name: VidyoTenantCapabilities}
 	{parent: VidyoUser}
 	{description: Represents the server side tenant capabilities for the user.}
	{member:
 		{name: isScheduledRoomEnabled}
 		{type: LmiBool}
 		{description: indicates if the creation of a scheduled meeting room is supported on the backend. }
 	}
 	{member:
 		{name: isGuestEnabled}
 		{type: LmiBool}
 		{description: indicates if the guest login is supported on the backend. }
 	}
 	{member:
 		{name: isRoomModerationEnabled}
 		{type: LmiBool}
 		{description: indicates if the room moderation is supported on the backend.}
 	}
 	{member:
 		{name: isLoginBannerEnabled}
 		{type: LmiBool}
 		{description: indicates if the login banner is enabled on the backend.}
 	}
 	{member:
 		{name: isWelcomeBannerEnabled}
 		{type: LmiBool}
 		{description: indicates if the welcome banner is enabled on the backend.}
 	}
 	{member:
 		{name: isPublicChatEnabled}
 		{type: LmiBool}
 		{description: indicates if public chat is enabled on the backend.}
 	}
 	{member:
 		{name: isCreatePublicRoomEnabled}
 		{type: LmiBool}
 		{description: indicates if creation of public rooms is enabled on the backend.}
 	}
 	{member:
 		{name: minimumRoomPinLength}
 		{type: LmiInt}
 		{description: represents the minimum room pin length required by the backend.}
 	}
	{member:
 		{name: maximumRoomPinLength}
 		{type: LmiInt}
 		{description: represents the maximum room pin length required by the backend.}
	}
 	{member:
 		{name: loginBannerData}
 		{type: LmiString}
 		{description: Login banner text configured at the backend.}
 	}
 	{member:
 		{name: welcomeBannerData}
 		{type: LmiString}
 		{description: Welcome banner text configured at the backend.}
 	}
 	{member:
 		{name: LoginAttemptInfo}
 		{type: LmiVector(VidyoUserLoginInfo)}
 		{description: Vector of VidyoUserLoginInfo.}
 	}
 	{member:
 		{name: changePasswordUrl}
 		{type: LmiString}
 		{description: URL to change the password at the backend.}
 	}
 	{member:
 		{name: isTestCallEnabled}
 		{type: LmiBool}
 		{description: indicates if test call is enabled on the backend.}
 	}
 	{member:
 		{name: isPersonalRoomEnabled}
 		{type: LmiBool}
 		{description: indicates if personal room is enabled on the backend.}
 	}
 	{member:
 		{name: endpointBehavior}
 		{type: LmiVector(VidyoProperty)}
 		{description: endpoint behavior}
 	}
 	{member:
 		{name: isOpusAudioEnabled}
 		{type: LmiBool}
 		{description: indicates if the Opus Audio codec is enabled on the backend. }
 	}
 	{member:
 		{name: isSdk220Enabled}
 		{type: LmiBool}
 		{description: indicates if the SDK 220 is enabled on the router. }
 	}
 	{member:
 		{name: isWSGMicroserviceEnabled}
 		{type: LmiBool}
 		{description: Indicates if Web Socket Gateway is enabled.}
	}
 	{member:
 		{name: WSGMicroserviceAddress}
 		{type: LmiString}
 		{description: Address of Web Socket Gateway microservice. This information is valid only when WSGMicroservice is enabled}
 	}
 }
 */
typedef struct
{
	LmiBool isScheduledRoomEnabled;
	LmiBool isGuestEnabled;
	LmiBool isRoomModerationEnabled;
	LmiBool isLoginBannerEnabled;
	LmiBool isWelcomeBannerEnabled;
	LmiBool isPublicChatEnabled;
	LmiBool isCreatePublicRoomEnabled;
	LmiInt minimumRoomPinLength;
	LmiInt maximumRoomPinLength;
	LmiString loginBannerData;
	LmiString welcomeBannerData;
	LmiVector(VidyoUserLoginInfo) LoginAttemptInfo;
	LmiString changePasswordUrl;
	LmiBool isTestCallEnabled;
	LmiBool isPersonalRoomEnabled;
	LmiVector(VidyoProperty) endpointBehavior;
	LmiBool isOpusAudioEnabled;
	LmiBool isSdk220Enabled;
	LmiBool isWSGMicroserviceEnabled;
	LmiString WSGMicroserviceAddress;
}VidyoTenantCapabilities;

/**
 {function visibility="private":
 	{name: VidyoTenantCapabilitiesConstructDefault}
 	{parent: VidyoTenantCapabilities}
 	{description: Constructs an VidyoTenantCapabilities object.}
 	{prototype: VidyoTenantCapabilities *VidyoTenantCapabilitiesConstructDefault(VidyoTenantCapabilities *capabilities, LmiAllocator *alloc)}
 	{parameter: {name: capabilities} {description: The VidyoTenantCapabilities object to construct.}}
 	{parameter: {name: alloc} {description: An allocator to use for miscellaneous items.}}
 	{return: A pointer to a constructed object on success, or NULL on failure.}
 }
 */
VidyoTenantCapabilities *VidyoTenantCapabilitiesConstructDefault(VidyoTenantCapabilities *capabilities, LmiAllocator *alloc);

/**
 {function visibility="private":
 	{name:VidyoTenantCapabilitiesConstructCopy}
 	{parent: VidyoTenantCapabilities}
 	{description: Constructs an VidyoTenantCapabilities object as a copy of an existing object.}
 	{prototype: VidyoTenantCapabilities *VidyoTenantCapabilitiesConstructCopy(VidyoTenantCapabilities *c, const VidyoTenantCapabilities *p)}
 	{parameter: {name: c} {description: The VidyoTenantCapabilities object to construct.}}
 	{parameter: {name: p} {description: The existing VidyoTenantCapabilities object to copy.}}
 	{return: A pointer to a constructed object on success, or NULL on failure.}
 }
 */
VidyoTenantCapabilities *VidyoTenantCapabilitiesConstructCopy(VidyoTenantCapabilities *c, const VidyoTenantCapabilities *p);

/**
 {function visibility="private":
 	{name: VidyoTenantCapabilitiesDestruct}
 	{parent: VidyoTenantCapabilities}
 	{description: Destructs an VidyoTenantCapabilities object.}
 	{prototype: void VidyoTenantCapabilitiesDestruct(VidyoTenantCapabilities *c)}
 	{parameter: {name: c} {description: The VidyoTenantCapabilities object to destruct.}}
 }
 */
void VidyoTenantCapabilitiesDestruct(VidyoTenantCapabilities *c);

/**
{callback apigroup="simple":
	{name: VidyoUserOnLoginComplete}
	{parent: VidyoUser}
		{description: }
	{prototype: void (*VidyoUserOnLoginComplete)(VidyoUser* u, VidyoUserLoginResult result, LmiBool secure, VidyoTenantCapabilities* capabilities)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: result}
		{description: }
	}
	{parameter:
		{name: secure}
		{description: }
	}
 	{parameter:
 		{name: capabilities}
 		{description: }
 	}
}
*/
typedef void (*VidyoUserOnLoginComplete)(VidyoUser* u, VidyoUserLoginResult result, LmiBool secure, VidyoTenantCapabilities* capabilities);

/**
{callback apigroup="simple":
	{name: VidyoUserOnLoggedOut}
	{parent: VidyoUser}
		{description: }
	{prototype: void (*VidyoUserOnLoggedOut)(VidyoUser* u, VidyoUserLogoutReason reason)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: reason}
		{description: }
	}
}
*/
typedef void(*VidyoUserOnLoggedOut)(VidyoUser* u, VidyoUserLogoutReason reason);

/**
{callback apigroup="simple":
	{name: VidyoUserOnUserSearchResults}
	{parent: VidyoUser}
		{description: }
	{prototype: void (*VidyoUserOnUserSearchResults)(VidyoUser* u, const char* searchText, VidyoUserSearchResult searchResult, const LmiVector(VidyoContactInfo)* contacts, LmiSizeT numRecords)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: searchText}
		{description: }
	}
	{parameter:
		{name: searchResult}
		{description: }
	}
	{parameter:
		{name: contacts}
		{description: }
	}
	{parameter:
		{name: numRecords}
		{description: }
	}
}
*/
typedef void(*VidyoUserOnUserSearchResults)(VidyoUser* u, const char* searchText, VidyoUserSearchResult searchResult, const LmiVector(VidyoContactInfo)* contacts, LmiSizeT numRecords);

/**
{callback apigroup="simple":
	{name: VidyoUserOnRoomSearchResults}
	{parent: VidyoUser}
		{description: }
	{prototype: void (*VidyoUserOnRoomSearchResults)(VidyoUser* u, const char* searchText, VidyoUserSearchResult searchResult, const LmiVector(VidyoRoomInfo)* roomInfo, LmiSizeT numRecords)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: searchText}
		{description: }
	}
	{parameter:
		{name: searchResult}
		{description: }
	}
	{parameter:
		{name: roomInfo}
		{description: }
	}
	{parameter:
		{name: numRecords}
		{description: }
	}
}
*/
typedef void(*VidyoUserOnRoomSearchResults)(VidyoUser* u, const char* searchText, VidyoUserSearchResult searchResult, const LmiVector(VidyoRoomInfo)* roomInfo, LmiSizeT numRecords);

/**
{callback apigroup="simple":
	{name: VidyoUserOnRecentRoomResults}
	{parent: VidyoUser}
		{description: }
	{prototype: void (*VidyoUserOnRecentRoomResults)(VidyoUser* u, VidyoUserSearchResult searchResult, const LmiVector(VidyoRoomInfo)* roomInfo)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: searchResult}
		{description: }
	}
	{parameter:
		{name: roomInfo}
		{description: }
	}
}
*/
typedef void(*VidyoUserOnRecentRoomResults)(VidyoUser* u, VidyoUserSearchResult searchResult, const LmiVector(VidyoRoomInfo)* roomInfo);

/**
 {callback:
	{name: VidyoUserOnFavoriteRoomResults}
	{parent: VidyoUser}
        {description: }
	{prototype: void (*VidyoUserOnFavoriteRoomResults)(VidyoUser* u, VidyoUserSearchResult searchResult, const LmiVector(VidyoRoomInfo)* roomInfo)}
	{parameter:
        {name: u}
        {description: }
	}
	{parameter:
        {name: searchResult}
        {description: }
	}
	{parameter:
        {name: roomInfo}
        {description: }
	}
 }
 */
typedef void(*VidyoUserOnFavoriteRoomResults)(VidyoUser* u, VidyoUserSearchResult searchResult, const LmiVector(VidyoRoomInfo)* roomInfo);

/**
{callback apigroup="simple":
	{name: VidyoUserOnUpdateSelf}
	{parent: VidyoUser}
		{description: }
	{prototype: void (*VidyoUserOnUpdateSelf)(VidyoUser* u, const VidyoContact* contact)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: contact}
		{description: }
	}
}
*/
typedef void(*VidyoUserOnUpdateSelf)(VidyoUser* u, const VidyoContact* contact);

/**
{callback apigroup="simple":
	{name: VidyoUserOnUpdateRosterContact}
	{parent: VidyoUser}
		{description: }
	{prototype: void (*VidyoUserOnUpdateRosterContact)(VidyoUser* u, const VidyoContact* contact)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: contact}
		{description: }
	}
}
*/
typedef void(*VidyoUserOnUpdateRosterContact)(VidyoUser* u, const VidyoContact* contact);

/**
{callback apigroup="simple":
	{name: VidyoUserOnRemoveRosterContact}
	{parent: VidyoUser}
		{description: }
	{prototype: void (*VidyoUserOnRemoveRosterContact)(VidyoUser* u, const LmiString* uri)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: uri}
		{description: }
	}
}
*/
typedef void(*VidyoUserOnRemoveRosterContact)(VidyoUser* u, const LmiString* uri);

/**
{callback apigroup="simple":
	{name: VidyoUserOnGetContactResult}
	{parent: VidyoUser}
	{description: }
	{prototype: void (*VidyoUserOnGetContactResult)(VidyoUser* u, const VidyoContact* contact, VidyoUserGetContactResult result)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: contact}
		{description: }
	}
	{parameter:
		{name: result}
		{description: }
	}
}
*/
typedef void (*VidyoUserOnGetContactResult)(VidyoUser* u, const VidyoContact* contact, VidyoUserGetContactResult result);

/**
{callback:
	{name: VidyoUserOnLicenseReceived}
	{parent: VidyoUser}
	{description: Informs about new license received by VidyoUser}
	{prototype: void (*VidyoUserOnLicenseReceived)(VidyoUser* u, const LmiString* licenseKey)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: licenseKey}
		{description: }
	}
}
*/
typedef void(*VidyoUserOnLicenseReceived)(VidyoUser* u, const LmiString* licenseKey);

/**
{callback:
	{name: VidyoUserOnGetLicenseKey}
	{parent: VidyoUser}
	{description: Requests the license key that was presumably stored when received via VidyoUserLicenseReceivedCallback}
	{prototype: void (*VidyoUserOnGetLicenseKey)(VidyoUser* u, LmiString* licenseKey)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: licenseKey}
		{description: }
	}
}
*/
typedef void(*VidyoUserOnGetLicenseKey)(VidyoUser* u, LmiString* licenseKey);

/**
{callback:
	{name: VidyoUserOnCallCreatedByInvite}
	{parent: VidyoUser}
		{description: }
	{prototype: void (*VidyoUserOnCallCreatedByInvite)(VidyoUser* u, VidyoCall* call, const VidyoContact* inviter)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: call}
		{description: }
	}
	{parameter:
		{name: inviter}
		{description: }
	}
}
*/
typedef void(*VidyoUserOnCallCreatedByInvite)(VidyoUser* u, VidyoCall* call, const VidyoContact* inviter);

/**
{callback:
	{name: VidyoUserOnCallCreated}
	{parent: VidyoUser}
		{description: }
	{prototype: void (*VidyoUserOnCallCreated)(VidyoUser* u, VidyoCall* call, VidyoUserCallCreateResult result, const LmiString *createToken)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: call}
		{description: }
	}
	{parameter:
		{name: result}
		{description: }
	}
	{parameter:
		{name: createToken}
		{description: }
	}
}
*/
typedef void(*VidyoUserOnCallCreated)(VidyoUser* u, VidyoCall* call, VidyoUserCallCreateResult result, const LmiString *createToken);

/**
{callback apigroup="simple":
	{name: VidyoUserOnRoomCreatedByInvite}
	{parent: VidyoUser}
		{description: }
	{prototype: void (*VidyoUserOnRoomCreatedByInvite)(VidyoUser* u, VidyoRoom* room, const VidyoContact* inviter, const char* message)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: room}
		{description: }
	}
	{parameter:
		{name: inviter}
		{description: }
	}
	{parameter:
		{name: message}
		{description: }
	}
}
*/
typedef void(*VidyoUserOnRoomCreatedByInvite)(VidyoUser* u, VidyoRoom* room, const VidyoContact* inviter, const char* message);

/**
 {callback:
	{name: VidyoUserOnRoomInviteCancelled}
	{parent: VidyoUser}
	{description: }
	{prototype: void (*VidyoUserOnRoomInviteCancelled)(VidyoUser* u, VidyoRoomInfo* roomInfo, const char* message)}
        {parameter:
     		{name: u}
     		{description: }
        }
        {parameter:
     		{name: roomInfo}
     		{description: }
        }
        {parameter:
     		{name: message}
     		{description: }
	}
 }
 */
typedef void(*VidyoUserOnRoomInviteCancelled)(VidyoUser* u,VidyoRoomInfo* roomInfo, const char* message);

/**
{callback apigroup="simple":
	{name: VidyoUserOnRoomCreated}
	{parent: VidyoUser}
		{description: }
	{prototype: void (*VidyoUserOnRoomCreated)(VidyoUser* u, VidyoRoom* room, VidyoUserRoomCreateResult result, const LmiString *createToken)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: room}
		{description: }
	}
	{parameter:
		{name: result}
		{description: }
	}
	{parameter:
		{name: createToken}
		{description: }
	}
}
*/
typedef void(*VidyoUserOnRoomCreated)(VidyoUser* u, VidyoRoom* room, VidyoUserRoomCreateResult result, const LmiString *createToken);

/**
{callback apigroup="simple":
	{name: VidyoUserOnConnectionStatusChanged}
	{parent: VidyoUser}
		{description: }
	{prototype: void (*VidyoUserOnConnectionStatusChanged)(VidyoUser* u, VidyoUserConnectionStatusChangedReason reason)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: reason}
		{description: }
	}
}
*/
typedef void(*VidyoUserOnConnectionStatusChanged)(VidyoUser* u, VidyoUserConnectionStatusChangedReason reason);

/**
{callback apigroup="simple":
	{name: VidyoUserOnTokenReceived}
	{parent: VidyoUser}
		{description: }
	{prototype: void (*VidyoUserOnTokenReceived)(VidyoUser* u, LmiString *token, VidyoUserTokenType tokenType)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: token}
		{description: }
	}
	{parameter:
		{name: tokenType}
		{description: }
	}
}
*/
typedef void(*VidyoUserOnTokenReceived)(VidyoUser* u, LmiString *token, VidyoUserTokenType tokenType);

/**
{callback apigroup="simple":
	{name: VidyoUserOnWebProxyCredentialsRequest}
	{parent: VidyoUser}
	{description: }
	{prototype: void (*VidyoUserOnWebProxyCredentialsRequest)(VidyoUser* u, LmiString *webProxyAddress)}
	{parameter:
		{name: u}
		{description: }
	}
 	{parameter:
 		{name: webProxyAddress}
 		{description: }
 	}
}
*/
typedef void(*VidyoUserOnWebProxyCredentialsRequest)(VidyoUser* u, LmiString *webProxyAddress);

/* This needs to be moved elsewhere */
/**
{type visibility="public":
	{name: VidyoUserGetAuthTypesResult}
	{parent: VidyoUser}
	{description: This type indicates the result of a search for user or room.}
		{value: {name: VIDYO_USERGETAUTHTYPESRESULT_OK} {description: The search operation was
		successful.}}
		{value: {name: VIDYO_USERGETAUTHTYPESRESULT_ConnectionFailed} {description: NThe Get Authentication Types
		result failed as connection failed.}}
		{value: {name: VIDYO_USERGETAUTHTYPESRESULT_ConnectionLost} {description: The Get Authentication Types
		result failed as connection was lost.}}
		{value: {name: VIDYO_USERGETAUTHTYPESRESULT_ConnectionTimeout} {description: The Get Authentication Types
		result failed due to request timeout.}}
		{value: {name: VIDYO_USERGETAUTHTYPESRESULT_NoResponse} {description: The Get Authentication Types
		result failed as there was no response from the server.}}
		{value: {name: VIDYO_USERGETAUTHTYPESRESULT_WebProxyAuthenticationFailed} {description: The Get Authentication Types
		result failed as the web proxy address required authentication.}}
		{value: {name: VIDYO_USERGETAUTHTYPESRESULT_TlsFailed} {description: The Get Authentication Types
		result failed as the tls handshake failed.}}
		{value: {name: VIDYO_USERGETAUTHTYPESRESULT_ServiceUnavailable} {description: The Get Authentication Types
		result failed as the service was unavailable.}}
		{value: {name: VIDYO_USERGETAUTHTYPESRESULT_MiscLocalError} {description: The Get Authentication Types
		result failed due to some miscellaneous local problem.}}
		{value: {name: VIDYO_USERGETAUTHTYPESRESULT_MiscRemoteError} {description: The Get Authentication Types failed due to some miscellaneous remote problem.}}
        {value: {name: VIDYO_USERGETAUTHTYPESRESULT_UnSupportedTenantVersion} {description: The Get Authentication Types failed as the version of tenant/backend not supported.}}
		{value: {name: VIDYO_USERGETAUTHTYPESRESULT_NoValidNetworkInterface} {description: The Get Authentication Types failed as there is no valid network interface available.}}
}
*/
typedef enum
{
	VIDYO_USERGETAUTHTYPESRESULT_OK,
	VIDYO_USERGETAUTHTYPESRESULT_ConnectionFailed,
	VIDYO_USERGETAUTHTYPESRESULT_ConnectionLost,
	VIDYO_USERGETAUTHTYPESRESULT_ConnectionTimeout,
	VIDYO_USERGETAUTHTYPESRESULT_NoResponse,
	VIDYO_USERGETAUTHTYPESRESULT_TlsFailed,
	VIDYO_USERGETAUTHTYPESRESULT_ServiceUnavailable,
	VIDYO_USERGETAUTHTYPESRESULT_WebProxyAuthenticationFailed,
	VIDYO_USERGETAUTHTYPESRESULT_MiscLocalError,
	VIDYO_USERGETAUTHTYPESRESULT_MiscRemoteError,
    VIDYO_USERGETAUTHTYPESRESULT_UnSupportedTenantVersion,
	VIDYO_USERGETAUTHTYPESRESULT_NoValidNetworkInterface
} VidyoUserGetAuthTypesResult;

/**
{callback:
	{name: VidyoUserOnAuthTypes}
	{parent: VidyoUser}
	{description: }
	{prototype: void (*VidyoUserOnAuthTypes)(VidyoUser* u, VidyoUserGetAuthTypesResult result, const LmiVector(VidyoUserAuthenticationInfo)* authTypes)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: result}
		{description: }
	}
	{parameter:
		{name: authTypes}
		{description: }
	}
}
*/
typedef void(*VidyoUserOnAuthTypes)(VidyoUser* u, VidyoUserGetAuthTypesResult result, const LmiVector(VidyoUserAuthenticationInfo)* authTypes);

/**
{function visibility="private":
	{name: VidyoUserInitialize}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserInitialize(void)}
	{return: }
}
*/
LmiBool VidyoUserInitialize(void);

/**
{function visibility="private":
	{name: VidyoUserUninitialize}
	{parent: VidyoUser}
	{description: }
	{prototype: void VidyoUserUninitialize(void)}
}
*/
void VidyoUserUninitialize(void);

/**
{type:
	{name: VidyoUserState}
	{parent: VidyoUser}
	{description: }
	{value: {name: VIDYO_USERSTATE_Idle} {description: }}
	{value: {name: VIDYO_USERSTATE_LoggingIn} {description: }}
	{value: {name: VIDYO_USERSTATE_LoggedIn} {description: }}
	{value: {name: VIDYO_USERSTATE_Reconnecting} {description: }}
	{value: {name: VIDYO_USERSTATE_RequestingAuthenticationTypes} {description: }}
}
*/
typedef enum {
	VIDYO_USERSTATE_Idle,
	VIDYO_USERSTATE_LoggingIn,
	VIDYO_USERSTATE_LoggedIn,
	VIDYO_USERSTATE_Reconnecting,
	VIDYO_USERSTATE_RequestingAuthenticationTypes,
} VidyoUserState;

/**
{function apigroup="simple":
	{name: VidyoUserConstruct}
	{parent: VidyoUser}
	{description: }
	{prototype: VidyoUser* VidyoUserConstruct(VidyoUser* user, VidyoEndpoint* endpoint, LmiAllocator* alloc)}
	{parameter:
		{name: user}
		{description: }
	}
	{parameter:
		{name: endpoint}
		{description: }
	}
	{parameter:
		{name: alloc}
		{description: }
	}
	{return: }
}
*/
VidyoUser* VidyoUserConstruct(VidyoUser* user, VidyoEndpoint* endpoint, LmiAllocator* alloc);

/**
{function apigroup="simple":
	{name: VidyoUserConstructCopy}
	{parent: VidyoUser}
	{description: Constructs an VidyoUser object as a copy of another.}
	{prototype: VidyoUser *VidyoUserConstructCopy(VidyoUser *obj, const VidyoUser *other)}
	{parameter: {name: obj} {description: The VidyoUser object to construct.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to a constructed object on success, or NULL on failure.}
}
*/

/**
{function apigroup="simple":
	{name: VidyoUserDestruct}
	{parent: VidyoUser}
	{description: Destructs an VidyoUser object.}
	{prototype: void VidyoUserDestruct(VidyoUser *obj)}
	{parameter: {name: obj} {description: The VidyoUser object to destruct.}}
}
*/

/**
{function visibility="private":
	{name: VidyoUserAssign}
	{parent: VidyoUser}
	{description: Assigns one VidyoUser object the value of another. }
	{prototype: VidyoUser *VidyoUserAssign(VidyoUser *obj, const VidyoUser *other)}
	{parameter: {name: obj} {description: The VidyoUser object.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to the destination object on success, or NULL on failure.}
}
*/

/**
{function visibility="private":
	{name: VidyoUserGetHandle}
	{parent: VidyoUser}
	{description: }
	{prototype: const VidyoUserHandle* VidyoUserGetHandle(const VidyoUser* u)}
	{parameter:
		{name: u}
		{description: }
	}
	{return: }
}
*/
const VidyoUserHandle* VidyoUserGetHandle(const VidyoUser* u);

/**
{function:
	{name: VidyoUserGetEndpoint}
	{parent: VidyoUser}
	{description: }
	{prototype: VidyoEndpoint* VidyoUserGetEndpoint(VidyoUser* u)}
	{parameter:
		{name: u}
		{description: }
	}
	{return: }
}
*/
VidyoEndpoint* VidyoUserGetEndpoint(VidyoUser* u);

/**
{function visibility="private":
	{name: VidyoUserSetUserData}
	{parent: VidyoUser}
	{description: }
	{prototype: void VidyoUserSetUserData(VidyoUser* u, LmiVoidPtr userData)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
}
*/
void VidyoUserSetUserData(VidyoUser* u, LmiVoidPtr userData);

/**
{function visibility="private":
	{name: VidyoUserGetUserData}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiVoidPtr VidyoUserGetUserData(const VidyoUser* u)}
	{parameter:
		{name: u}
		{description: }
	}
	{return: }
}
*/
LmiVoidPtr VidyoUserGetUserData(const VidyoUser* u);

/**
 {function apigroup="simple":
	{name: VidyoUserRegisterContactEventListener}
	{parent: VidyoUser}
	{description: Registers to get notified about contact events.}
	{prototype: LmiBool VidyoUserRegisterContactEventListener(VidyoUser* u, VidyoUserOnUpdateSelf onUpdateSelf, VidyoUserOnUpdateRosterContact onUpdateRosterContact, VidyoUserOnRemoveRosterContact onRemoveRosterContact)}
	{parameter:
		{name: u}
		{description: The VidyoUser object.}
	}
	{parameter:
		{name: onUpdateSelf}
		{description: Callback that is triggered when the users' own contact information changes.}
	}
	{parameter:
		{name: onUpdateRosterContact}
		{description: Callback that is triggered when a roster contact is updated.}
	}
	{parameter:
		{name: onRemoveRosterContact}
		{description: Callback that is triggered when a contact is removed from the roster .}
	}
	{return: LMI_TRUE on success, LMI_FALSE on failure.}
}
*/
LmiBool VidyoUserRegisterContactEventListener(VidyoUser* u, VidyoUserOnUpdateSelf onUpdateSelf, VidyoUserOnUpdateRosterContact onUpdateRosterContact, VidyoUserOnRemoveRosterContact onRemoveRosterContact);

/**
 {function apigroup="simple":
	{name: VidyoUserUnregisterContactEventListener}
	{parent: VidyoUser}
	{description: Unregisters contact event notifications.}
	{prototype: LmiBool VidyoUserUnregisterContactEventListener(VidyoUser* u)}
	{parameter:
		{name: u}
		{description: The VidyoUser object.}
	}
	{return: LMI_TRUE on success, LMI_FALSE on failure.}
}
*/
LmiBool VidyoUserUnregisterContactEventListener(VidyoUser* u);

/**
 {function :
	{name: VidyoUserRegisterCallEventListener}
	{parent: VidyoUser}
	{description: Registers to get notified about invite to call events.}
	{prototype: LmiBool VidyoUserRegisterCallEventListener(VidyoUser* u, VidyoUserOnCallCreatedByInvite onCallCreatedByInvite)}
	{parameter:
		{name: u}
		{description: The VidyoUser object.}
	}
	{parameter:
		{name: onCallCreatedByInvite}
		{description: Callback that is triggered when the user is being invited to a call.}
	}
	{return: LMI_TRUE on success, LMI_FALSE on failure.}
}
*/
LmiBool VidyoUserRegisterCallEventListener(VidyoUser* u, VidyoUserOnCallCreatedByInvite onCallCreatedByInvite);

/**
 {function apigroup="simple":
	{name: VidyoUserUnregisterCallEventListener}
	{parent: VidyoUser}
	{description: Unregisters call event notifications.}
	{prototype: LmiBool VidyoUserUnregisterCallEventListener(VidyoUser* u)}
	{parameter:
		{name: u}
		{description: The VidyoUser object.}
	}
	{return: LMI_TRUE on success, LMI_FALSE on failure.}
}
*/
LmiBool VidyoUserUnregisterCallEventListener(VidyoUser* u);

/**
 {function apigroup="simple":
	{name: VidyoUserRegisterRoomEventListener}
	{parent: VidyoUser}
	{description: Registers to get notified about invite to room events.}
	{prototype: LmiBool VidyoUserRegisterRoomEventListener(VidyoUser* u, VidyoUserOnRoomCreatedByInvite onRoomCreatedByInvite, VidyoUserOnRoomInviteCancelled onRoomInviteCancelled)}
	{parameter:
		{name: u}
		{description: The VidyoUser object.}
	}
	{parameter:
		{name: onRoomCreatedByInvite}
		{description: Callback that is triggered when the user is being invited to a room.}
	}
 	{parameter:
 		{name: onRoomInviteCancelled}
 		{description: .}
	}
	{return: LMI_TRUE on success, LMI_FALSE on failure.}
}
*/
LmiBool VidyoUserRegisterRoomEventListener(VidyoUser* u, VidyoUserOnRoomCreatedByInvite onRoomCreatedByInvite, VidyoUserOnRoomInviteCancelled onRoomInviteCancelled);

/**
 {function apigroup="simple":
	{name: VidyoUserUnregisterRoomEventListener}
	{parent: VidyoUser}
	{description: Unregisters room event notifications.}
	{prototype: LmiBool VidyoUserUnregisterRoomEventListener(VidyoUser* u)}
	{parameter:
		{name: u}
		{description: The VidyoUser object.}
	}
	{return: LMI_TRUE on success, LMI_FALSE on failure.}
}
*/
LmiBool VidyoUserUnregisterRoomEventListener(VidyoUser* u);

/**
 {function:
	{name: VidyoUserRegisterLicenseEventListener}
	{parent: VidyoUser}
	{description: Registers to get notified about license events.}
	{prototype: LmiBool VidyoUserRegisterLicenseEventListener(VidyoUser* u, VidyoUserOnLicenseReceived onLicenseReceived, VidyoUserOnGetLicenseKey onGetLicenseKey)}
	{parameter:
		{name: u}
		{description: The VidyoUser object.}
	}
	{parameter:
		{name: onLicenseReceived}
		{description: Callback that is triggered when the new license is received from the server.}
	}
	{parameter:
		{name: onGetLicenseKey}
		{description: Callback that is triggered when the user needs a previousely received license key.}
	}
	{return: LMI_TRUE on success, LMI_FALSE on failure.}
}
*/
LmiBool VidyoUserRegisterLicenseEventListener(VidyoUser* u, VidyoUserOnLicenseReceived onLicenseReceived, VidyoUserOnGetLicenseKey onGetLicenseKey);

/**
 {function apigroup="simple":
 {name: VidyoUserUnregisterLicenseEventListener}
 {parent: VidyoUser}
 {description: Unregisters license event notifications.}
 {prototype: LmiBool VidyoUserUnregisterLicenseEventListener(VidyoUser* u)}
 {parameter:
 {name: u}
 {description: The VidyoUser object.}
 }
 {return: LMI_TRUE on success, LMI_FALSE on failure.}
 }
 */
LmiBool VidyoUserUnregisterLicenseEventListener(VidyoUser* u);


/**
{function apigroup="simple":
	{name: VidyoUserGetId}
	{parent: VidyoUser}
	{description: }
	{prototype: const LmiString *VidyoUserGetId(const VidyoUser* u)}
	{parameter:
		{name: u}
		{description: }
	}
	{return: The ID of the user}
}
*/
const LmiString *VidyoUserGetId(const VidyoUser* u);

/**
{function:
	{name: VidyoUserGetWebProxyAddress}
	{parent: VidyoUser}
	{description: }
	{prototype: const LmiString *VidyoUserGetWebProxyAddress(const VidyoUser* u)}
	{parameter:
		{name: u}
		{description: }
	}
	{return: The address of the WebProxy}
}
*/
const LmiString *VidyoUserGetWebProxyAddress(const VidyoUser* u);

/**
{function apigroup="simple":
	{name: VidyoUserSetWebProxyAddressCredentials}
	{parent: VidyoUser}
	{description: }
	{prototype: void VidyoUserSetWebProxyAddressCredentials(VidyoUser* u, const char* proxyAddress, const char* username, const char* password)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: proxyAddress}
		{description: }
	}
	{parameter:
		{name: username}
		{description: }
	}
	{parameter:
		{name: password}
		{description: }
	}
}
*/
void VidyoUserSetWebProxyAddressCredentials(VidyoUser* u, const char* proxyAddress, const char* username, const char* password);

/**
{function:
	{name: VidyoUserSetCA}
	{parent: VidyoUser}
	{description: }
	{prototype: void VidyoUserSetCA(VidyoUser* u, const char* ca, const char* caFilePath, const char* caDir)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: ca}
        {description: The contents of the Certificate Authority file. Note: If the string 'default' is passed here, VidyoUser will use a built-in Certificate Authroity bundle.}
	}
	{parameter:
		{name: caFilePath}
		{description: The full path Certificate Authority file. }
	}
	{parameter:
		{name: caDir}
		{description: The full path to the directory containing Certificate Authority files. }
	}
}
*/
void VidyoUserSetCA(VidyoUser* u, const char* ca, const char* caFilePath, const char* caDir);

/**
{function:
	{name: VidyoUserSetUDPTransport}
	{parent: VidyoUser}
	{description: }
	{prototype: void VidyoUserSetUDPTransport(VidyoUser* u, LmiBool enable)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: enable}
		{description: Enable the tranport. }
	}
}
*/
void VidyoUserSetUDPTransport(VidyoUser *u, LmiBool enable);

/**
{function:
	{name: VidyoUserSetTCPTransport}
	{parent: VidyoUser}
	{description: }
	{prototype: void VidyoUserSetTCPTransport(VidyoUser* u, LmiBool enable)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: enable}
		{description: Enable the tranport. }
	}
}
*/
void VidyoUserSetTCPTransport(VidyoUser *u, LmiBool enable);

/**
{function:
	{name: VidyoUserSetWebProxyTransport}
	{parent: VidyoUser}
	{description: }
	{prototype: void VidyoUserSetWebProxyTransport(VidyoUser* u, LmiBool enable)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: enable}
		{description: Enable the tranport. }
	}
}
*/
void VidyoUserSetWebProxyTransport(VidyoUser *u, LmiBool enable);

/* Login */
/**
{function apigroup="simple":
	{name: VidyoUserLogin}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserLogin(VidyoUser* u, const char* username, const char* password, const char* host, LmiUint port, const char* serviceType, VidyoUserOnLoginComplete onLoginComplete, VidyoUserOnLoggedOut onLoggedOut, VidyoUserOnConnectionStatusChanged onConnectionStatusChanged, VidyoUserOnTokenReceived onTokenReceived, VidyoUserOnWebProxyCredentialsRequest onWebProxyCredentialsRequest)}
	{parameter:
		{name: u}
		{description: Pointer to the VidyoUser object.}
	}
	{parameter:
		{name: username}
		{description: Username of the user logging in. }
	}
	{parameter:
		{name: password}
		{description: Password of the user logging in. }
	}
	{parameter:
		{name: host}
		{description: Hostname or the IP address of the server. }
	}
	{parameter:
		{name: port}
		{description: Optional port of the server. Default is "5222" for xmpp, "443" for wss. }
	}
	{parameter:
		{name: serviceType}
		{description: Optional type of the service. Default is "wss". }
	}
	{parameter:
		{name: onLoginComplete}
		{description: Callback that is triggered when the user login operation is complete. This could be a successful login or a failure to login due to credentials, hostname, etc. }
	}
	{parameter:
		{name: onLoggedOut}
		{description: Callback that is triggered when the user is logged out. }
	}
	{parameter:
		{name: onConnectionStatusChanged}
		{description: Callback that is triggered when the user's connection status temporarily changes due to network lag and might be re-established without logging out. }
	}
	{parameter:
		{name: onTokenReceived}
		{description: Callback that is triggered when the user receives a token that can be used for subsequent logins. This token can be stored in stead of a password. }
	}
	{parameter:
		{name: onWebProxyCredentialsRequest}
		{description: Callback that is triggered when the user is behind a web proxy which requires credentials to establish a connection. }
	}
	{return: }
}
*/
LmiBool VidyoUserLogin(VidyoUser* u, const char* username, const char* password, const char* host, LmiUint port, const char* serviceType, VidyoUserOnLoginComplete onLoginComplete, VidyoUserOnLoggedOut onLoggedOut, VidyoUserOnConnectionStatusChanged onConnectionStatusChanged, VidyoUserOnTokenReceived onTokenReceived, VidyoUserOnWebProxyCredentialsRequest onWebProxyCredentialsRequest);

/**
{function apigroup="simple":
	{name: VidyoUserLoginWithTenantToken}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserLoginWithTenantToken(VidyoUser* u, const char* provisionToken, const char* host, LmiUint port, const char* serviceType, VidyoUserOnLoginComplete onLoginComplete, VidyoUserOnLoggedOut onLoggedOut, VidyoUserOnConnectionStatusChanged onConnectionStatusChanged, VidyoUserOnTokenReceived onTokenReceived, VidyoUserOnWebProxyCredentialsRequest onWebProxyCredentialsRequest)}
	{parameter:
		{name: u}
		{description: Pointer to the VidyoUser object.}
	}
	{parameter:
		{name: provisionToken}
		{description: The provision token used to login. }
	}
	{parameter:
		{name: host}
		{description: Hostname or the IP address of the server. }
	}
	{parameter:
		{name: port}
		{description: Optional port of the server. Default is "5222" for xmpp, "443" for wss. }
	}
	{parameter:
		{name: serviceType}
		{description: Optional type of the service. Default is "wss". }
	}
	{parameter:
		{name: onLoginComplete}
		{description: Callback that is triggered when the user login operation is complete. This could be a successful login or a failure to login due to credentials, hostname, etc. }
	}
	{parameter:
		{name: onLoggedOut}
		{description: Callback that is triggered when the user is logged out. }
	}
	{parameter:
		{name: onConnectionStatusChanged}
		{description: Callback that is triggered when the user's connection status temporarily changes due to network lag and might be re-established without logging out. }
	}
	{parameter:
		{name: onTokenReceived}
		{description: Callback that is triggered when the user receives a token that can be used for subsequent logins. This token can be stored in stead of a password. }
	}
	{parameter:
		{name: onWebProxyCredentialsRequest}
		{description: Callback that is triggered when the user is behind a web proxy which requires credentials to establish a connection. }
	}
	{return: }
}
*/
LmiBool VidyoUserLoginWithTenantToken(VidyoUser* u, const char* provisionToken, const char* host, LmiUint port, const char* serviceType, VidyoUserOnLoginComplete onLoginComplete, VidyoUserOnLoggedOut onLoggedOut, VidyoUserOnConnectionStatusChanged onConnectionStatusChanged, VidyoUserOnTokenReceived onTokenReceived, VidyoUserOnWebProxyCredentialsRequest onWebProxyCredentialsRequest);

/**
{function apigroup="simple":
	{name: VidyoUserLoginWithAccessToken}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserLoginWithAccessToken(VidyoUser* u, const char* accessToken, const char* host, LmiUint port, const char* serviceType, VidyoUserOnLoginComplete onLoginComplete, VidyoUserOnLoggedOut onLoggedOut, VidyoUserOnConnectionStatusChanged onConnectionStatusChanged, VidyoUserOnTokenReceived onTokenReceived, VidyoUserOnWebProxyCredentialsRequest onWebProxyCredentialsRequest)}
	{parameter:
		{name: u}
		{description: Pointer to the VidyoUser object.}
	}
	{parameter:
		{name: accessToken}
		{description: The short-term token used to re-login. }
	}
	{parameter:
		{name: host}
		{description: Hostname or the IP address of the server. }
	}
	{parameter:
		{name: port}
		{description: Optional port of the server. Default is "5222" for xmpp, "443" for wss. }
	}
	{parameter:
		{name: serviceType}
		{description: Optional type of the service. Default is "wss". }
	}
	{parameter:
		{name: onLoginComplete}
		{description: Callback that is triggered when the user login operation is complete. This could be a successful login or a failure to login due to credentials, hostname, etc. }
	}
	{parameter:
		{name: onLoggedOut}
		{description: Callback that is triggered when the user is logged out. }
	}
	{parameter:
		{name: onConnectionStatusChanged}
		{description: Callback that is triggered when the user's connection status temporarily changes due to network lag and might be re-established without logging out. }
	}
	{parameter:
		{name: onTokenReceived}
		{description: Callback that is triggered when the user receives a token that can be used for subsequent logins. This token can be stored in stead of a password. }
	}
	{parameter:
		{name: onWebProxyCredentialsRequest}
		{description: Callback that is triggered when the user is behind a web proxy which requires credentials to establish a connection. }
	}
	{return: }
	{note: A Tenant token should only be used when logging into vidyo.io or similar service}
}
*/
LmiBool VidyoUserLoginWithAccessToken(VidyoUser* u, const char* accessToken, const char* host, LmiUint port, const char* serviceType, VidyoUserOnLoginComplete onLoginComplete, VidyoUserOnLoggedOut onLoggedOut, VidyoUserOnConnectionStatusChanged onConnectionStatusChanged, VidyoUserOnTokenReceived onTokenReceived, VidyoUserOnWebProxyCredentialsRequest onWebProxyCredentialsRequest);

/**
{function apigroup="simple":
	{name: VidyoUserLoginWithRefreshToken}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserLoginWithRefreshToken(VidyoUser* u, const char* refreshToken, const char* host, LmiUint port, const char* serviceType, VidyoUserOnLoginComplete onLoginComplete, VidyoUserOnLoggedOut onLoggedOut, VidyoUserOnConnectionStatusChanged onConnectionStatusChanged, VidyoUserOnTokenReceived onTokenReceived, VidyoUserOnWebProxyCredentialsRequest onWebProxyCredentialsRequest)}
	{parameter:
		{name: u}
		{description: Pointer to the VidyoUser object.}
	}
	{parameter:
		{name: refreshToken}
		{description: The short-term token used to re-login. }
	}
	{parameter:
		{name: host}
		{description: Hostname or the IP address of the server. }
	}
	{parameter:
		{name: port}
		{description: Optional port of the server. Default is "5222" for xmpp, "443" for wss. }
	}
	{parameter:
		{name: serviceType}
		{description: Optional type of the service. Default is "wss". }
	}
	{parameter:
		{name: onLoginComplete}
		{description: Callback that is triggered when the user login operation is complete. This could be a successful login or a failure to login due to credentials, hostname, etc. }
	}
	{parameter:
		{name: onLoggedOut}
		{description: Callback that is triggered when the user is logged out. }
	}
	{parameter:
		{name: onConnectionStatusChanged}
		{description: Callback that is triggered when the user's connection status temporarily changes due to network lag and might be re-established without logging out. }
	}
	{parameter:
		{name: onTokenReceived}
		{description: Callback that is triggered when the user receives a token that can be used for subsequent logins. This token can be stored in stead of a password. }
	}
	{parameter:
		{name: onWebProxyCredentialsRequest}
		{description: Callback that is triggered when the user is behind a web proxy which requires credentials to establish a connection. }
	}
	{return: }
	{note: A Refresh token should only be used when LoginWithAccessToken failed}
}
*/
LmiBool VidyoUserLoginWithRefreshToken(VidyoUser* u, const char* refreshToken, const char* host, LmiUint port, const char* serviceType, VidyoUserOnLoginComplete onLoginComplete, VidyoUserOnLoggedOut onLoggedOut, VidyoUserOnConnectionStatusChanged onConnectionStatusChanged, VidyoUserOnTokenReceived onTokenReceived, VidyoUserOnWebProxyCredentialsRequest onWebProxyCredentialsRequest);

/**
{function apigroup="simple":
	{name: VidyoUserLoginAsGuest}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserLoginAsGuest(VidyoUser* u, const char* displayName, const char* roomKey, const char* host, LmiUint port, const char* serviceType, VidyoUserOnLoginComplete onLoginComplete, VidyoUserOnLoggedOut onLoggedOut, VidyoUserOnConnectionStatusChanged onConnectionStatusChanged, VidyoUserOnTokenReceived onTokenReceived, VidyoUserOnWebProxyCredentialsRequest onWebProxyCredentialsRequest)}
	{parameter:
		{name: u}
		{description: Pointer to the VidyoUser object.}
	}
	{parameter:
		{name: displayName}
		{description: Display name of the guest user. }
	}
	{parameter:
		{name: roomKey}
		{description:key to the room the guest user is attempting to join. }
	}
	{parameter:
		{name: host}
		{description: Hostname or the IP address of the server. }
	}
	{parameter:
		{name: port}
		{description: Optional port of the server. Default is "5222" for xmpp, "443" for wss. }
	}
	{parameter:
		{name: serviceType}
		{description: Optional type of the service. Default is "wss". }
	}
	{parameter:
		{name: onLoginComplete}
		{description: Callback that is triggered when the user login operation is complete. This could be a successful login or a failure to login due to credentials, hostname, etc. }
	}
	{parameter:
		{name: onLoggedOut}
		{description: Callback that is triggered when the user is logged out. }
	}
	{parameter:
		{name: onConnectionStatusChanged}
		{description: Callback that is triggered when the user's connection status temporarily changes due to network lag and might be re-established without logging out. }
	}
	{parameter:
		{name: onTokenReceived}
		{description: Callback that is triggered when the user receives a token that can be used for subsequent logins. This token can be stored in stead of a password. }
	}
	{parameter:
		{name: onWebProxyCredentialsRequest}
		{description: Callback that is triggered when the user is behind a web proxy which requires credentials to establish a connection. }
	}
	{return: }
}
*/
LmiBool VidyoUserLoginAsGuest(VidyoUser* u, const char* displayName, const char* roomKey, const char* host, LmiUint port, const char* serviceType, VidyoUserOnLoginComplete onLoginComplete, VidyoUserOnLoggedOut onLoggedOut, VidyoUserOnConnectionStatusChanged onConnectionStatusChanged, VidyoUserOnTokenReceived onTokenReceived, VidyoUserOnWebProxyCredentialsRequest onWebProxyCredentialsRequest);

/**
{function:
	{name: VidyoUserLoginWithCAC}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserLoginWithCAC(VidyoUser* u, const char* certificate, const char* host, LmiUint port, const char* serviceType, VidyoUserOnLoginComplete onLoginComplete, VidyoUserOnLoggedOut onLoggedOut, VidyoUserOnConnectionStatusChanged onConnectionStatusChanged, VidyoUserOnTokenReceived onTokenReceived, VidyoUserOnWebProxyCredentialsRequest onWebProxyCredentialsRequest)}
	{parameter:
		{name: u}
		{description: Pointer to the VidyoUser object.}
	}
	{parameter:
		{name: certificate}
		{description: The certificate used to login. }
	}
	{parameter:
		{name: host}
		{description: Hostname or the IP address of the server. }
	}
	{parameter:
		{name: port}
		{description: Optional port of the server. Default is "5222". }
	}
	{parameter:
		{name: serviceType}
		{description: Optional type of the service. Default is "xmpp". }
	}
 	{parameter:
 		{name: onLoginComplete}
 		{description: Callback that is triggered when the user login operation is complete. This could be a successful login or a failure to login due to credentials, hostname, etc. }
 	}
 	{parameter:
 		{name: onLoggedOut}
 		{description: Callback that is triggered when the user is logged out. }
 	}
 	{parameter:
 		{name: onConnectionStatusChanged}
 		{description: Callback that is triggered when the user's connection status temporarily changes due to network lag and might be re-established without logging out. }
 	}
 	{parameter:
 		{name: onTokenReceived}
 		{description: Callback that is triggered when the user receives a token that can be used for subsequent logins. This token can be stored in stead of a password. }
 	}
 	{parameter:
 		{name: onWebProxyCredentialsRequest}
 		{description: Callback that is triggered when the user is behind a web proxy which requires credentials to establish a connection. }
 	}
	{return: }
}
*/
LmiBool VidyoUserLoginWithCAC(VidyoUser* u, const char* certificate, const char* host, LmiUint port, const char* serviceType, VidyoUserOnLoginComplete onLoginComplete, VidyoUserOnLoggedOut onLoggedOut, VidyoUserOnConnectionStatusChanged onConnectionStatusChanged, VidyoUserOnTokenReceived onTokenReceived, VidyoUserOnWebProxyCredentialsRequest onWebProxyCredentialsRequest);

/**
 {function:
	{name: VidyoUserLoginWithSAML}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserLoginWithSAML(VidyoUser* u, const char* key, const char* host, LmiUint port, const char* serviceType, VidyoUserOnLoginComplete onLoginComplete, VidyoUserOnLoggedOut onLoggedOut, VidyoUserOnConnectionStatusChanged onConnectionStatusChanged, VidyoUserOnTokenReceived onTokenReceived, VidyoUserOnWebProxyCredentialsRequest onWebProxyCredentialsRequest)}
	{parameter:
 		{name: u}
 		{description: Pointer to the VidyoUser object.}
	}
	{parameter:
 		{name: key}
 		{description: The SAML key or assertion recieved from the Portal/IDP. }
	}
	{parameter:
 		{name: host}
 		{description: Hostname or the IP address of the server. }
	}
	{parameter:
 		{name: port}
 		{description: Optional port of the server. Default is "5222". }
	}
	{parameter:
 		{name: serviceType}
 		{description: Optional type of the service. Default is "xmpp". }
	}
 	{parameter:
 		{name: onLoginComplete}
 		{description: Callback that is triggered when the user login operation is complete. This could be a successful login or a failure to login due to credentials, hostname, etc. }
 	}
	{parameter:
 		{name: onLoggedOut}
 		{description: Callback that is triggered when the user is logged out. }
 	}
 	{parameter:
 		{name: onConnectionStatusChanged}
 		{description: Callback that is triggered when the user's connection status temporarily changes due to network lag and might be re-established without logging out. }
 	}
 	{parameter:
 		{name: onTokenReceived}
 		{description: Callback that is triggered when the user receives a token that can be used for subsequent logins. This token can be stored in stead of a password. }
 	}
 	{parameter:
 		{name: onWebProxyCredentialsRequest}
 		{description: Callback that is triggered when the user is behind a web proxy which requires credentials to establish a connection. }
 	}
	{return: }
 }
 */

LmiBool VidyoUserLoginWithSAML(VidyoUser* u, const char* key, const char* host, LmiUint port, const char* serviceType, VidyoUserOnLoginComplete onLoginComplete, VidyoUserOnLoggedOut onLoggedOut, VidyoUserOnConnectionStatusChanged onConnectionStatusChanged, VidyoUserOnTokenReceived onTokenReceived, VidyoUserOnWebProxyCredentialsRequest onWebProxyCredentialsRequest);

/**
{function apigroup="simple":
	{name: VidyoUserLogout}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserLogout(VidyoUser* user)}
	{parameter:
		{name: user}
		{description: }
	}
	{return: }
}
*/
LmiBool VidyoUserLogout(VidyoUser* user);

/**
 {function apigroup="simple":
 	{name: VidyoUserInvalidateTokenOnLogout}
 	{parent: VidyoUser}
 	{description: Set a flag to invalidates token received via VidyoUserOnTokenReceived callback during logout.}
 	{prototype: LmiBool VidyoUserInvalidateTokenOnLogout(VidyoUser* user, LmiBool invalidate)}
 	{parameter:
 		{name: user}
 		{description: }
 	}
 	{parameter:
 		{name: invalidate}
 		{description: }
 	}
 	{return: }
 }
 */
LmiBool VidyoUserInvalidateTokenOnLogout(VidyoUser* user, LmiBool invalidate);

/* Roster */
/**
{function apigroup="simple":
	{name: VidyoUserSearchUsers}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserSearchUsers(VidyoUser* u, const char* searchText, LmiUint index, LmiUint pageSize, VidyoUserOnUserSearchResults onUserSearchResults)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: searchText}
		{description: }
	}
	{parameter:
		{name: index}
		{description: }
	}
	{parameter:
		{name: pageSize}
		{description: }
	}
	{parameter:
		{name: onUserSearchResults}
		{description: Callback that is triggered when the user search results are ready.}
	}
	{return: }
}
*/
LmiBool VidyoUserSearchUsers(VidyoUser* u, const char* searchText, LmiUint index, LmiUint pageSize, VidyoUserOnUserSearchResults onUserSearchResults);

/**
{function apigroup="simple":
	{name: VidyoUserSearchRooms}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserSearchRooms(VidyoUser* u, const char* searchText, LmiUint index, LmiUint pageSize, VidyoUserOnRoomSearchResults onRoomSearchResults)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: searchText}
		{description: }
	}
	{parameter:
		{name: index}
		{description: }
	}
	{parameter:
		{name: pageSize}
		{description: }
	}
	{parameter:
		{name: onRoomSearchResults}
		{description: Callback that is triggered when the room search results are ready.}
	}
	{return: }
}
*/
LmiBool VidyoUserSearchRooms(VidyoUser* u, const char* searchText, LmiUint index, LmiUint pageSize, VidyoUserOnRoomSearchResults onRoomSearchResults);

/**
{function apigroup="simple":
	{name: VidyoUserSearchConversationRooms}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserSearchConversationRooms(VidyoUser* u, const char* searchText, LmiUint index, LmiUint pageSize, VidyoUserOnRoomSearchResults onRoomSearchResults)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: searchText}
		{description: }
	}
	{parameter:
		{name: index}
		{description: }
	}
	{parameter:
		{name: pageSize}
		{description: }
	}
	{parameter:
		{name: onRoomSearchResults}
		{description: Callback that is triggered when the room search results are ready.}
	}
	{return: }
}
*/
LmiBool VidyoUserSearchConversationRooms(VidyoUser* u, const char* searchText, LmiUint index, LmiUint pageSize, VidyoUserOnRoomSearchResults onRoomSearchResults);

/**
{function apigroup="simple":
	{name: VidyoUserSearchTopicRooms}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserSearchTopicRooms(VidyoUser* u, const char* searchText, LmiUint index, LmiUint pageSize, VidyoUserOnRoomSearchResults onRoomSearchResults)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: searchText}
		{description: }
	}
	{parameter:
		{name: index}
		{description: }
	}
	{parameter:
		{name: pageSize}
		{description: }
	}
	{parameter:
		{name: onRoomSearchResults}
		{description: Callback that is triggered when the room search results are ready.}
	}
	{return: }
}
*/
LmiBool VidyoUserSearchTopicRooms(VidyoUser* u, const char* searchText, LmiUint index, LmiUint pageSize, VidyoUserOnRoomSearchResults onRoomSearchResults);

Declare_LmiBasicType(VidyoUserSearchField)
Declare_LmiBasicType(VidyoRoomSearchField)
Declare_LmiBasicType(VidyoRoomSearchFieldRelation)
Declare_LmiVector(VidyoUserSearchField)
Declare_LmiVector(VidyoRoomSearchField)
Declare_LmiVector(VidyoRoomSearchFieldRelation)

/**
{function:
	{name: VidyoUserAdvancedSearchUsers}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserAdvancedSearchUsers(VidyoUser* u, const LmiVector(VidyoUserSearchField)* fieldSet, const LmiVector(LmiString)* fieldValues, const char* searchToken, LmiUint index, LmiUint pageSize, VidyoUserOnUserSearchResults onUserSearchResults)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: fieldSet}
		{description: }
	}
	{parameter:
		{name: fieldValues}
		{description: }
	}
	{parameter:
		{name: searchToken}
		{description: }
	}
	{parameter:
		{name: index}
		{description: }
	}
	{parameter:
		{name: pageSize}
		{description: }
	}
	{parameter:
		{name: onUserSearchResults}
		{description: Callback that is triggered when the user search results are ready.}
	}
	{return: }
}
*/
LmiBool VidyoUserAdvancedSearchUsers(VidyoUser* u, const LmiVector(VidyoUserSearchField)* fieldSet, const LmiVector(LmiString)* fieldValues, const char* searchToken, LmiUint index, LmiUint pageSize, VidyoUserOnUserSearchResults onUserSearchResults);

/**
{function:
	{name: VidyoUserAdvancedSearchRooms}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserAdvancedSearchRooms(VidyoUser* u, const LmiVector(VidyoRoomSearchField)* fieldSet, const LmiVector(VidyoRoomSearchFieldRelation)* fieldRelations, const LmiVector(LmiString)* fieldValues, const char* searchToken, LmiUint index, LmiUint pageSize, VidyoUserOnRoomSearchResults onRoomSearchResults)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: fieldSet}
		{description: }
	}
	{parameter:
		{name: fieldRelations}
		{description: }
	}
	{parameter:
		{name: fieldValues}
		{description: }
	}
	{parameter:
		{name: searchToken}
		{description: }
	}
	{parameter:
		{name: index}
		{description: }
	}
	{parameter:
		{name: pageSize}
		{description: }
	}
	{parameter:
		{name: onRoomSearchResults}
		{description: Callback that is triggered when the room search results are ready.}
	}
	{return: }
}
*/
LmiBool VidyoUserAdvancedSearchRooms(VidyoUser* u, const LmiVector(VidyoRoomSearchField)* fieldSet, const LmiVector(VidyoRoomSearchFieldRelation)* fieldRelations, const LmiVector(LmiString)* fieldValues, const char* searchToken, LmiUint index, LmiUint pageSize, VidyoUserOnRoomSearchResults onRoomSearchResults);


/**
{function apigroup="simple":
	{name: VidyoUserSearchRoomsWithSubject}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserSearchRoomsWithSubject(VidyoUser* u, const char* searchText, LmiUint index, LmiUint pageSize, VidyoUserOnRoomSearchResults onRoomSearchResults)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: searchText}
		{description: }
	}
	{parameter:
		{name: index}
		{description: }
	}
	{parameter:
		{name: pageSize}
		{description: }
	}	
	{parameter:
		{name: onRoomSearchResults}
		{description: Callback that is triggered when the room search results are ready.}
	}
	{return: }
}
*/
LmiBool VidyoUserSearchRoomsWithSubject(VidyoUser* u, const char* searchText, LmiUint index, LmiUint pageSize, VidyoUserOnRoomSearchResults onRoomSearchResults);


/**
{function apigroup="simple":
	{name: VidyoUserSearchRoomsWithName}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserSearchRoomsWithName(VidyoUser* u, const char* searchText, LmiUint index, LmiUint pageSize, VidyoUserOnRoomSearchResults onRoomSearchResults)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: searchText}
		{description: }
	}
	{parameter:
		{name: index}
		{description: }
	}
	{parameter:
		{name: pageSize}
		{description: }
	}
	{parameter:
		{name: onRoomSearchResults}
		{description: Callback that is triggered when the room search results are ready.}
	}
	{return: }
}
*/
LmiBool VidyoUserSearchRoomsWithName(VidyoUser* u, const char* searchText, LmiUint index, LmiUint pageSize, VidyoUserOnRoomSearchResults onRoomSearchResults);


/**
{function apigroup="simple":
	{name: VidyoUserSearchRoomsWithOwner}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserSearchRoomsWithOwner(VidyoUser* u, const char* searchText, LmiUint index, LmiUint pageSize, VidyoUserOnRoomSearchResults onRoomSearchResults)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: searchText}
		{description: }
	}
	{parameter:
		{name: index}
		{description: }
	}
	{parameter:
		{name: pageSize}
		{description: }
	}
	{parameter:
		{name: onRoomSearchResults}
		{description: Callback that is triggered when the room search results are ready.}
	}
	{return: }
}
*/
LmiBool VidyoUserSearchRoomsWithOwner(VidyoUser* u, const char* searchText, LmiUint index, LmiUint pageSize, VidyoUserOnRoomSearchResults onRoomSearchResults);


/**
{function apigroup="simple":
	{name: VidyoUserGetRecentRooms}
	{parent: VidyoUser}
	{description: Get the recent rooms of the user.}
	{prototype: LmiBool VidyoUserGetRecentRooms(VidyoUser* u, LmiUint index, LmiUint pageSize, VidyoUserOnRecentRoomResults onRecentRoomResults)}
	{parameter:
		{name: u}
		{description: Vidyo user object.}
	}
	{parameter:
		{name: index}
		{description: The start index from which the recent rooms are required. A value of '0' represents
			rooms starting from the beginning. A value of 'n' represents rooms starting from 'n'th record.
			This is used for paging the response.}
	}
	{parameter:
		{name: pageSize}
		{description: The maximum number of room records that can be sent in the response. 
			This is used for paging the response.}
	}
	{parameter:
		{name: onRecentRoomResults}
		{description: Callback that is triggered when the recent room search results are ready.}
	}
	{return: }
}
*/
LmiBool VidyoUserGetRecentRooms(VidyoUser* u, LmiUint index, LmiUint pageSize, VidyoUserOnRecentRoomResults onRecentRoomResults);

/**
{function apigroup="simple":
	{name: VidyoUserUpdatePresence}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserUpdatePresence(VidyoUser* u, VidyoContactPresenceState state, const char *status)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: state}
		{description: }
	}
	{parameter:
		{name: status}
		{description: }
	}
	{return: }
}
*/
LmiBool VidyoUserUpdatePresence(VidyoUser* u, VidyoContactPresenceState state, const char *status);

/**
{function apigroup="simple":
	{name: VidyoUserSetDisplayName}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserSetDisplayName(VidyoUser* u, const char* displayName)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: displayName}
		{description: The maximum length of the display name is 256 characters.}
	}
	{return: LMI_TRUE if the display name was set, LMI_FALSE if length of the display name is longer than 256 characters.}
}
*/
LmiBool VidyoUserSetDisplayName(VidyoUser* u, const char* displayName);

/**
{function apigroup="simple":
	{name: VidyoUserAddRosterContact}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserAddRosterContact(VidyoUser* u, const LmiString* userId)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: userId}
		{description: }
	}
	{return: }
}
*/
LmiBool VidyoUserAddRosterContact(VidyoUser* u, const LmiString* userId);

/**
{function apigroup="simple":
	{name: VidyoUserRemoveRosterContact}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserRemoveRosterContact(VidyoUser* u, const LmiString* userId)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: userId}
		{description: }
	}
	{return: }
}
*/
LmiBool VidyoUserRemoveRosterContact(VidyoUser* u, const LmiString* userId);

/**
{function:
	{name: VidyoUserGetCurrentRoster}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserGetCurrentRoster(VidyoUser* u, LmiVector(VidyoContact)* roster)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: roster}
		{description: }
	}
	{return: }
}
*/
LmiBool VidyoUserGetCurrentRoster(VidyoUser* u, LmiVector(VidyoContact)* roster);

/**
 {function:
	{name: VidyoUserGetFavoriteRooms}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserGetFavoriteRooms(VidyoUser* u, LmiUint index, LmiUint pageSize, VidyoUserOnFavoriteRoomResults onFavoriteRoomResults)}
	{parameter:
        {name: u}
        {description: }
	}
	{parameter:
        {name: index}
        {description: The start index from which the recent rooms are required. A value of '0' represents
            rooms starting from the beginning. A value of 'n' represents rooms starting from 'n'th record.
            This is used for paging the response.}
        }
        {parameter:
            {name: pageSize}
            {description: The maximum number of room records that can be sent in the response.
            This is used for paging the response.}
	}
	{parameter:
		{name: onFavoriteRoomResults}
		{description: Callback that is triggered when the favorite room search results are ready.}
	}
	{return: }
 }
 */
LmiBool VidyoUserGetFavoriteRooms(VidyoUser* u, LmiUint index, LmiUint pageSize, VidyoUserOnFavoriteRoomResults onFavoriteRoomResults);

/**
{function:
	{name: VidyoUserAllowSubscriber}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserAllowSubscriber(VidyoUser* u, const LmiString* userId)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: userId}
		{description: }
	}
	{return: }
}
*/
LmiBool VidyoUserAllowSubscriber(VidyoUser* u, const LmiString* userId);

/**
{function:
	{name: VidyoUserBlockSubscriber}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserBlockSubscriber(VidyoUser* u, const LmiString* userId)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: userId}
		{description: }
	}
	{return: }
}
*/
LmiBool VidyoUserBlockSubscriber(VidyoUser* u, const LmiString* userId);

/**
{function apigroup="simple":
	{name: VidyoUserGetContact}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserGetContact(VidyoUser* u, const LmiString* userId, VidyoUserOnGetContactResult onGetContactResult)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: userId}
		{description: }
	}
	{parameter:
		{name: onGetContactResult}
		{description: Callback that is triggered when the contact search results are ready.}
	}
	{return: }
}
*/
LmiBool VidyoUserGetContact(VidyoUser* u, const LmiString* userId, VidyoUserOnGetContactResult onGetContactResult);

/**
{function:
	{name: VidyoUserCreateCall}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserCreateCall(VidyoUser* u, const LmiString *userId, LmiString *createToken, VidyoUserOnCallCreated onCallCreated)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: userId}
		{description: }
	}
	{parameter:
		{name: createToken}
		{description: }
	}
	{parameter:
		{name: onCallCreated}
		{description: Callback that is triggered when the call creation results are ready.}
	}
	{return: }
}
*/
LmiBool VidyoUserCreateCall(VidyoUser* u, const LmiString *userId, LmiString *createToken, VidyoUserOnCallCreated onCallCreated);

/**
{function visibility="private":
	{name: VidyoUserGetCalls}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserGetCalls(VidyoUser *u, LmiVector(VidyoCall) *calls)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: calls}
		{description: }
	}
	{return: }
}
*/
LmiBool VidyoUserGetCalls(VidyoUser *u, LmiVector(VidyoCall) *calls);

/**
{function apigroup="simple":
	{name: VidyoUserCreateRoomWithId}
	{parent: VidyoUser}
	{description: Gets a room with the id specified and provides a new VidyoRoom object in the VidyoUserFeedbackRoomCreated callback.}
	{prototype: LmiBool VidyoUserCreateRoomWithId(VidyoUser *u, const char *id, const char *createToken, VidyoUserOnRoomCreated onRoomCreated)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: id}
		{description: }
	}
	{parameter:
		{name: createToken}
		{description: }
	}
	{parameter:
		{name: onRoomCreated}
		{description: Callback that is triggered when the room creation results are ready.}
	}
	{return: }
	{note: If the room with the specified id does not exist it will be created with default properties. }
}
*/
LmiBool VidyoUserCreateRoomWithId(VidyoUser *u, const char *id, const char *createToken, VidyoUserOnRoomCreated onRoomCreated);

/**
{function apigroup="simple":
	{name: VidyoUserCreateRoomFromId}
	{parent: VidyoUser}
	{description: Finds and existing room with the id specified and provides a new VidyoRoom object in the VidyoUserFeedbackRoomCreated callback.}
	{prototype: LmiBool VidyoUserCreateRoomFromId(VidyoUser *u, const char *id, LmiString *createToken, VidyoUserOnRoomCreated onRoomCreated)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: id}
		{description: }
	}
	{parameter:
		{name: createToken}
		{description: }
	}
	{parameter:
		{name: onRoomCreated}
		{description: Callback that is triggered when the room creation results are ready.}
	}
	{return: }
	{note: If the room with the specified id does not exist, the VidyoUserFeedbackRoomCreated callback will return failure. }
}
*/
LmiBool VidyoUserCreateRoomFromId(VidyoUser *u, const char *id, LmiString *createToken, VidyoUserOnRoomCreated onRoomCreated);


/**
 {function:
	{name: VidyoUserCreateScheduledRoom}
	{parent: VidyoUser}
	{description: Creates a new scheduled room and provides a new VidyoRoom object in the VidyoUserFeedbackRoomCreated callback.}
	{prototype: LmiBool VidyoUserCreateScheduledRoom(VidyoUser *u, const VidyoEventSchedule *schedule, const LmiString *createToken, VidyoUserOnRoomCreated onRoomCreated)}
	{parameter:
        {name: u}
        {description: }
	}
	{parameter:
        {name: schedule}
        {description: }
	}
	{parameter:
        {name: createToken}
        {description: }
	}
 	{parameter:
 		{name: onRoomCreated}
 		{description: Callback that is triggered when the room creation results are ready.}
 	}
	{return: }
 }
 */
LmiBool VidyoUserCreateScheduledRoom(VidyoUser *u, const VidyoEventSchedule *schedule, const LmiString *createToken, VidyoUserOnRoomCreated onRoomCreated);

/**
{function:
    {name: VidyoUserCreateTestCallRoom}
    {parent: VidyoUser}
    {description: Creates a test call room and provides a new VidyoRoom object in the VidyoUserFeedbackRoomCreated callback.}
    {prototype: LmiBool VidyoUserCreateTestCallRoom(VidyoUser *u, LmiString *createToken, VidyoUserOnRoomCreated onRoomCreated)}
    {parameter:
        {name: u}
        {description: }
    }
    {parameter:
        {name: createToken}
        {description: }
    }
 	{parameter:
 		{name: onRoomCreated}
 		{description: Callback that is triggered when the room creation results are ready.}
 	}
    {return: }
}
*/
LmiBool VidyoUserCreateTestCallRoom(VidyoUser *u, LmiString *createToken, VidyoUserOnRoomCreated onRoomCreated);

/**
{function apigroup="simple":
	{name: VidyoUserCreateTopicRoom}
	{parent: VidyoUser}
	{description: Creates a new topic room and privdes a new VidyoRoom object in the VidyoUserFeedbackRoomCreated callback.}
	{prototype: LmiBool VidyoUserCreateTopicRoom(VidyoUser *u, const char *name, const char *description, LmiString *createToken, VidyoUserOnRoomCreated onRoomCreated)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: name}
		{description: }
	}
	{parameter:
		{name: description}
		{description: }
	}
	{parameter:
		{name: createToken}
		{description: }
	}
	{parameter:
		{name: onRoomCreated}
		{description: Callback that is triggered when the room creation results are ready.}
	}
	{return: }
}
*/
LmiBool VidyoUserCreateTopicRoom(VidyoUser *u, const char *name, const char *description, LmiString *createToken, VidyoUserOnRoomCreated onRoomCreated);

/**
{function apigroup="simple":
	{name: VidyoUserGetConversationRoom}
	{parent: VidyoUser}
	{description: Finds a Conversation room and privdes a new VidyoRoom object in the VidyoUserFeedbackRoomCreated callback.}
	{prototype: LmiBool VidyoUserGetConversationRoom(VidyoUser *u, const LmiVector(LmiString) *userIds, LmiString *createToken, VidyoUserOnRoomCreated onRoomCreated)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: userIds}
		{description: }
	}
	{parameter:
		{name: createToken}
		{description: }
	}
	{parameter:
		{name: onRoomCreated}
		{description: Callback that is triggered when the room creation results are ready.}
	}
	{return: }
	{note: This methos has a "Get or Create" semantic since Conversation rooms are auto-created. }
}
*/
LmiBool VidyoUserGetConversationRoom(VidyoUser* u, const LmiVector(LmiString) *userIds, LmiString *createToken, VidyoUserOnRoomCreated onRoomCreated);

/**
{function visibility="private":
	{name: VidyoUserGetRooms}
	{parent: VidyoUser}
	{description: }
	{prototype: LmiBool VidyoUserGetRooms(VidyoUser *u, LmiVector(VidyoRoom) *rooms)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: rooms}
		{description: }
	}
	{return: }
}
*/
LmiBool VidyoUserGetRooms(VidyoUser *u, LmiVector(VidyoRoom) *rooms);

/**
{function visibility="private":
	{name: VidyoUserIsLicensed}
	{parent: VidyoUser}
	{description: Get the licensing status of the user.}
	{prototype: LmiBool VidyoUserIsLicensed(VidyoUser* u)}
	{parameter:
		{name: u}
		{description: Vidyo user object.}
	}
	{return: LMI_TRUE if licensed, LMI_FALSE if not licensed}
}
*/
LmiBool VidyoUserIsLicensed(VidyoUser* u);

/**
{function visibility="private":
	{name: VidyoUserConstructPortalServiceTransportAddress}
	{parent: VidyoUser}
	{description: Construct transport address with certificate authorities.}
	{prototype: void VidyoUserConstructPortalServiceTransportAddress(VidyoLmiTransportAddress* address, VidyoTransport* transport, LmiBool tls, const VidyoTlsConfig *tlsConfig)}
	{parameter:
		{name: address}
		{description: Transport address.}
	}
	{parameter:
		{name: transport}
		{description: Transport.}
	}
	{parameter:
		{name: tls}
		{description: tls flag.}
	}
	{parameter:
		{name: tlsConfig}
		{description: tls configuration.}
	}
}
*/
void VidyoUserConstructPortalServiceTransportAddress(VidyoLmiTransportAddress* address, VidyoTransport* transport, LmiBool tls, const VidyoTlsConfig *tlsConfig);

/**
{function:
	{name: VidyoUserCreateRoomFromKey}
	{parent: VidyoUser}
	{description: Finds a room based on the room key and privdes a new VidyoRoom object in the VidyoUserFeedbackRoomCreated callback.}
	{prototype: LmiBool VidyoUserCreateRoomFromKey(VidyoUser* u, const char* roomKey, LmiString *createToken, VidyoUserOnRoomCreated onRoomCreated)}
	{parameter:
		{name: u}
		{description: }
	}
	{parameter:
		{name: roomKey}
		{description: }
	}
	{parameter:
		{name: createToken}
		{description: }
	}
 	{parameter:
 		{name: onRoomCreated}
 		{description: Callback that is triggered when the room creation results are ready.}
 	}
	{return: }
}
*/
LmiBool VidyoUserCreateRoomFromKey(VidyoUser* u, const char* roomKey, LmiString *createToken, VidyoUserOnRoomCreated onRoomCreated);

/**
{function apigroup="simple":
	{name: VidyoUserGetStats}
	{parent: VidyoUser}
	{description: Fill in data in VidyoUserStats from a room.}
	{prototype: LmiBool VidyoUserGetStats(VidyoUser *r, VidyoUserStats *stats)}
	{parameter: {name: r} {description: The user object to extract stats.}}
	{parameter: {name: stats} {description: The stats object to fill.}}
	{return: LMI_TRUE on success.}
}
*/
LmiBool VidyoUserGetStats(VidyoUser *u, VidyoUserStats *stats);

/**
 {callback apigroup="simple":
 	{name: VidyoUserOnAuthTypesWebProxyCredentialsRequest}
 	{parent: VidyoUser}
 	{description: }
 	{prototype: void (*VidyoUserOnAuthTypesWebProxyCredentialsRequest)(VidyoUser* u, LmiString *webProxyAddress)}
 	{parameter:
 		{name: u}
 		{description: }
 	}
 	{parameter:
 		{name: webProxyAddress}
 		{description: }
 	}
 }
 */
typedef void(*VidyoUserOnAuthTypesWebProxyCredentialsRequest)(VidyoUser* u, LmiString *webProxyAddress);

/**
{function:
	{name: VidyoUserGetAuthTypes}
	{parent: VidyoUser}
	{description: Get the supported authentication types for the user.}
	{prototype: LmiBool VidyoUserGetAuthTypes(VidyoUser *u,const char* host, LmiUint port, const char* serviceType, VidyoUserOnAuthTypes onAuthTypes, VidyoUserOnAuthTypesWebProxyCredentialsRequest onWebProxyCredentialsRequest)}
	{parameter: 
		{name: u} 
		{description: The user object to authentication types.}}
	{parameter:
		{name: host}
		{description: Hostname or the IP address of the server. }
	}
	{parameter:
		{name: port}
		{description: Optional port of the server. Default is "5222". }
	}
	{parameter:
		{name: serviceType}
		{description: Optional type of the service. Default is "xmpp". }
	}
 	{parameter:
 		{name: onAuthTypes}
 		{description: callback. }
 	}
 	{parameter:
 		{name: onWebProxyCredentialsRequest}
 		{description: Callback that is triggered when the user is behind a web proxy which requires credentials to establish a connection. }
 	}
	{return: LMI_TRUE on success.}
}
*/
LmiBool VidyoUserGetAuthTypes(VidyoUser *u,const char* host, LmiUint port, const char* serviceType, VidyoUserOnAuthTypes onAuthTypes, VidyoUserOnAuthTypesWebProxyCredentialsRequest onWebProxyCredentialsRequest);

/**
 {callback apigroup="simple":
 	{name: VidyoUserOnPasswordResetUrl}
 	{parent: VidyoUser}
 	{description: }
 	{prototype: void(*VidyoUserOnPasswordResetUrl)(VidyoUser* u, LmiString *passwordResetUrl)}
 	{parameter:
 		{name: u}
 		{description: }
 	}
 	{parameter:
 		{name: passwordResetUrl}
 		{description: }
 	}
 }
 */
typedef void(*VidyoUserOnPasswordResetUrl)(VidyoUser* u, LmiString *passwordResetUrl);

/**
 {function:
 	{name: VidyoUserGetPasswordResetUrl}
 	{parent: VidyoUser}
 	{description: Get an URL where user can reset his password.}
 	{prototype: LmiBool VidyoUserGetPasswordResetUrl(VidyoUser *u, VidyoUserOnPasswordResetUrl onPasswordResetUrl)}
 	{parameter:
 		{name: u}
 		{description: The user object.}}
 	{parameter:
 		{name: onPasswordResetUrl}
 		{description: Callback returns password reset URL. }
 	}
 	{return: LMI_TRUE on success.}
 }
 */
LmiBool VidyoUserGetPasswordResetUrl(VidyoUser *u, VidyoUserOnPasswordResetUrl onPasswordResetUrl);

/**
 {function:
 	{name: VidyoUserPauseUpdateNotification}
 	{parent: VidyoUser}
 	{description: Pause or resume update notifications.}
 	{prototype: LmiBool VidyoUserPauseUpdateNotification(VidyoUser *u, LmiBool pauseUpdateNotification)}
 	{parameter:
 		{name: u}
 		{description: The user object.}}
 	{parameter:
 		{name: pauseUpdateNotification}
 		{description: Set to true to resume update notificaiton, set to false to stop udpate notificaiton}
 	}
 	{return: LMI_TRUE on success.}
 }
 */
LmiBool VidyoUserPauseUpdateNotification(VidyoUser *u, LmiBool pauseUpdateNotification);

LMI_END_EXTERN_C

#if LMI_INLINE_NEED_HEADER_FILE_DEFINITIONS
#include "VidyoUserInline.h"
#endif

#endif /* VIDYO_USER_H_ */
    
    
