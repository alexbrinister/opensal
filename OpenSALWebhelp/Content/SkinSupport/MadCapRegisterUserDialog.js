/// <reference path="MadCapUtilities.js" />
/// <reference path="MadCapLiveHelpUtilities.js" />

// {{MadCap}} //////////////////////////////////////////////////////////////////
// Copyright: MadCap Software, Inc - www.madcapsoftware.com ////////////////////
////////////////////////////////////////////////////////////////////////////////
// <version>6.1.0.0</version>
////////////////////////////////////////////////////////////////////////////////

//
//    Class CMCRegisterUserDialog
//

function CMCRegisterUserDialog( winNode, dialogMode, version )
{
	CMCRegisterUserDialog.InCheckUserStatusMode = false;
	
	//
	
	CMCDialog.call( this, winNode );

	this.mItemInfos			= new Array();
	this.mDialogMode		= dialogMode;
	this.mVersion			= version;
	
	// Overridden properties
	
	this.StyleClass			= "RegisterUser";
	this.FontFamily			= "Arial";
	this.FontSize			= "12px";
	this.FontWeight			= "normal";
	this.FontStyle			= "normal";
	this.Color				= "#000000";
	this.TitleLabel			= "Create Feedback Service Profile:";
	this.TitleFontFamily	= "Arial";
	this.TitleFontSize		= "14px";
	this.TitleFontWeight	= "bold";
	this.TitleFontStyle		= "normal";
	this.TitleFontVariant	= "small-caps";
	this.TitleColor			= "#000000";
	this.BackgroundColor	= "#ffffcc";
	this.SubmitButtonLabel	= "Submit";
	this.CancelButtonLabel	= "Cancel";
	this.ShadowColor		= "#000000";
	this.ShadowDistance		= 5;
	this.ShadowOpacity		= 100;
	this.BorderLeft			= "solid 2px #000000";
	this.BorderRight		= "solid 2px #000000";
	this.BorderTop			= "solid 2px #000000";
	this.BorderBottom		= "solid 2px #000000";
	
	this.RegistrationMessage			= "You must create a user profile to post comments to this help system. Please fill in the information below. An email will be sent to the address you provide. Please follow the instructions in the email to complete activation. Fields marked with an asterisk (*) are required.";
	this.EditProfileRegistrationMessage	= "Use this form to update your profile information. If you choose to update your email address, an email will be sent to the address you provide. Please follow the instructions in the email to complete activation.";
	this.RegistrationSubmit				= "Your information has been sent to MadCap Software. When the information has been processed, you will receive an email with a link to a verification page. Click this link, or copy and paste the link into your Web browser to complete the registration.";
	this.RegistrationSubmitNote			= "NOTE: Some service providers have email filtering software that may cause the notification email to be sent to your junk email folder. If you do not receive a notification email, please check this folder to see if it has been sent there.";
	this.MissingRequiredField			= "Please enter a value for: ";
	this.UpdateSuccess					= "Your profile was updated successfully!";
}

CMCRegisterUserDialog.prototype = new CMCDialog();
CMCRegisterUserDialog.prototype.constructor = CMCRegisterUserDialog;
CMCRegisterUserDialog.prototype.base = CMCDialog.prototype;

CMCRegisterUserDialog.prototype.InnerHtml =	"" +
//											"<div id=\"RegisterUserDialog\" style=\"display: none;\">" +
//												"<div style=\"font-size: 14px; font-weight: bold; font-variant: small-caps;\">" +
//													"Create Feedback Service Profile:" +
//												"</div>" +
//												"" +
//												"<br />" +
//												"" +
												"<div id=\"MCRegistrationMessage\" class=\"Label\">" +
													"You must create a user profile to post comments to this help system. " +
													"Please fill in the information below. An email will be sent to the " +
													"address you provide. Please follow the instructions in the email to complete activation." +
													"Fields marked with an asterisk (*) are required." +
												"</div>" +
												"" +
												"<br />" +
												"" +
												"<table class=\"MCDialogOuterTable\">" +
													"<col style=\"width: 150px;\" />" +
													"<col style=\"width: auto;\" />" +
													"<tbody />" +
												"</table>" +
												"<div id=\"MCEmailNotificationsGroup\" style=\"margin-top: 10px;\">" +
													"<div id=\"MCEmailNotificationsGroupLabel\" class=\"Label\" style=\"text-decoration: underline;\">E-mail Notifications</div>" +
													"<div id=\"MCEmailNotificationsHeadingLabel\" class=\"Label\">I want to receive an email when...</div>" +
													"<div>" +
														"<div><label class=\"Label\"><input id=\"MCCommentReplyNotification\" type=\"checkbox\" /><span id=\"MCCommentReplyNotificationLabel\">a reply is left to one of my comments</span></label></div>" +
														"<div><label class=\"Label\"><input id=\"MCCommentSameTopicNotification\" type=\"checkbox\" /><span id=\"MCCommentSameTopicNotificationLabel\">a comment is left on a topic that I commented on</span></label></div>" +
														"<div><label class=\"Label\"><input id=\"MCCommentSameHelpSystemNotification\" type=\"checkbox\" /><span id=\"MCCommentSameHelpSystemNotificationLabel\">a comment is left on any topic in the Help system</span></label></div>" +
													"</div>" +
												"</div>" +
												"" +
												"<div style=\"text-align: right; margin-top: 20px;\">" +
													"<input id=\"MCDialogSubmit\" type=\"Submit\" value=\"Register User\" />" +
													"<input id=\"MCDialogCancel\" type=\"button\" value=\"Cancel\" />" +
												"</div>";
//											"</div>"

//	Enumerations

CMCRegisterUserDialog.DialogMode					= {};
CMCRegisterUserDialog.DialogMode.NewUserProfile		= 0;
CMCRegisterUserDialog.DialogMode.EditUserProfile	= 1;

//

CMCRegisterUserDialog.prototype.Create	= function()
{
	this.base.Create.call( this );
	
	var xmlDoc	= CMCXmlParser.GetXmlDoc( FMCGetSkinFolderAbsolute() + "Skin.xml", false, null, null );
	var items	= null;
	
	if ( this.mVersion == 1 )
	{
		items = new Array( 7 );
		items[0] = "Username";
		items[1] = "EmailAddress";
		items[2] = "FirstName";
		items[3] = "LastName";
		items[4] = "Country";
		items[5] = "PostalCode";
		items[6] = "Gender";
		
		var emailNotificationsGroup	= this.mWindow.document.getElementById( "MCEmailNotificationsGroup" );
		emailNotificationsGroup.style.display = "none";
	}
	else
	{
		items = FMCGetAttributeStringList( xmlDoc.documentElement, "FeedbackUserProfileItems", "|" );
		
		if ( items == null )
		{
			items = new Array();
		}
		
		if ( !items.Contains( "EmailAddress" ) )
		{
			items.Insert( "EmailAddress", 0 );
		}
		
		if ( !items.Contains( "Username" ) )
		{
			items.Insert( "Username", 0 );
		}
		
		var c = this.mWindow.document.getElementById( "MCCommentReplyNotification" );
		var itemInfo = new CMCItemInfo( "CommentReplyNotification", "CommentReplyNotification", c, false );
		this.mItemInfos[this.mItemInfos.length] = itemInfo;
		
		var savedValue = FMCLoadUserData( "CommentReplyNotification" );
		c.checked = savedValue == "true";
		
		c = this.mWindow.document.getElementById( "MCCommentSameTopicNotification" );
		itemInfo = new CMCItemInfo( "CommentSameTopicNotification", "CommentSameTopicNotification", c, false );
		this.mItemInfos[this.mItemInfos.length] = itemInfo;
		
		savedValue = FMCLoadUserData( "CommentSameTopicNotification" );
		c.checked = savedValue == "true";
		
		c = this.mWindow.document.getElementById( "MCCommentSameHelpSystemNotification" );
		itemInfo = new CMCItemInfo( "CommentSameHelpSystemNotification", "CommentSameHelpSystemNotification", c, false );
		this.mItemInfos[this.mItemInfos.length] = itemInfo;
		
		savedValue = FMCLoadUserData( "CommentSameHelpSystemNotification" );
		c.checked = savedValue == "true";
	}
	
	//

	var tbody	= this.RootEl.getElementsByTagName( "tbody" )[0];

	for ( var i = 0, length = items.length; i < length; i++ )
	{
		var item			= items[i];
		var label			= CMCFlareStylesheet.LookupValue( "FeedbackUserProfileItem", item, "Label", null );
		
		if ( label == null )
		{
			if ( CMCRegisterUserDialog.IsV1Item( item ) )
			{
				label = CMCRegisterUserDialog.LookupV1Style( item );
				
				if ( label == null )
				{
					label = CMCRegisterUserDialog.LookupDefaultStyleValue( item );
				}
			}
			else
			{
				label = item;
			}
		}
		
		var required		= null;
		
		if ( item == "Username" || item == "EmailAddress" || this.mVersion == 1 )
		{
			required = true;
		}
		else
		{
			required = FMCStringToBool( CMCFlareStylesheet.LookupValue( "FeedbackUserProfileItem", item, "Required", "false" ) );
		}
		
		var defaultValue	= CMCFlareStylesheet.LookupValue( "FeedbackUserProfileItem", item, "DefaultValue", "" );
		var savedValue		= FMCLoadUserData( item );
		
		if ( savedValue != null )
		{
			defaultValue = savedValue;
		}
		
		var tr				= this.mWindow.document.createElement( "tr" );
		var td				= this.mWindow.document.createElement( "td" );
		
		td.className = "Label";
		td.appendChild( this.mWindow.document.createTextNode( (required ? "*" : "") + label ) );
		tr.appendChild( td );

		td = this.mWindow.document.createElement( "td" );
		
		var controlEl	= null;
		
		if ( item == "Gender" )
		{
			var select	= this.mWindow.document.createElement( "select" );
			var option	= this.mWindow.document.createElement( "option" );
			option.setAttribute( "value", "" );
			select.appendChild( option );
			
			option = this.mWindow.document.createElement( "option" );
			option.setAttribute( "value", "female" );
			
			var femaleLabel	= CMCFlareStylesheet.LookupValue( "FeedbackUserProfileItem", item, "GenderFemaleName", null );
			
			if ( femaleLabel == null )
			{
				femaleLabel = CMCRegisterUserDialog.LookupV1Style( "GenderFemaleName" );
				
				if ( femaleLabel == null )
				{
					femaleLabel = "Female";
				}
			}
			
			option.appendChild( this.mWindow.document.createTextNode( femaleLabel ) );
			select.appendChild( option );
			
			option = this.mWindow.document.createElement( "option" );
			option.setAttribute( "value", "male" );
			
			var maleLabel	= CMCFlareStylesheet.LookupValue( "FeedbackUserProfileItem", item, "GenderMaleName", null );
			
			if ( maleLabel == null )
			{
				maleLabel = CMCRegisterUserDialog.LookupV1Style( "GenderMaleName" );
				
				if ( maleLabel == null )
				{
					maleLabel = "Male";
				}
			}
			
			option.appendChild( this.mWindow.document.createTextNode( maleLabel ) );
			select.appendChild( option );

			controlEl = select;
		}
		else
		{
			var input	= this.mWindow.document.createElement( "input" );
			input.setAttribute( "type", "text" );
			input.style.width = "200px";

			controlEl = input;
		}

		controlEl.value = defaultValue;
		
		td.appendChild( controlEl );
		tr.appendChild( td );
		tbody.appendChild( tr );
		
		var itemInfo	= new CMCItemInfo( item, label, controlEl, required );
		this.mItemInfos[this.mItemInfos.length] = itemInfo;
	}
}

CMCRegisterUserDialog.prototype.OnInitializing	= function()
{
	this.base.OnInitializing.call( this );
};

CMCRegisterUserDialog.prototype.LoadStyles	= function()
{
	if ( this.mDialogMode == CMCRegisterUserDialog.DialogMode.EditUserProfile )
	{
		this.TitleLabel = CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "EditProfileTitleLabel", "Edit Feedback Service Profile:" );
	}
	
	//
	
	this.base.LoadStyles.call( this );
	
	var registrationMessage = null;
	
	if ( this.mDialogMode == CMCRegisterUserDialog.DialogMode.NewUserProfile )
	{
		registrationMessage = CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "Registration", this.RegistrationMessage );
	}
	else
	{
		registrationMessage = CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "EditProfileRegistration", this.EditProfileRegistrationMessage );
	}
	
	document.getElementById( "MCRegistrationMessage" ).firstChild.nodeValue = registrationMessage;
	
	var emailNotificationsGroupLabel	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "EmailNotificationsGroupLabel", null );
	if ( emailNotificationsGroupLabel != null ) { document.getElementById( "MCEmailNotificationsGroupLabel" ).firstChild.nodeValue = emailNotificationsGroupLabel; }
	
	var emailNotificationsHeadingLabel	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "EmailNotificationsHeadingLabel", null );
	if ( emailNotificationsHeadingLabel != null ) { document.getElementById( "MCEmailNotificationsHeadingLabel" ).firstChild.nodeValue = emailNotificationsHeadingLabel; }
	
	var commentReplyNotificationLabel	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "CommentReplyNotificationLabel", null );
	if ( commentReplyNotificationLabel != null ) { document.getElementById( "MCCommentReplyNotificationLabel" ).firstChild.nodeValue = commentReplyNotificationLabel; }
	
	var commentSameTopicNotificationLabel	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "CommentSameTopicNotificationLabel", null );
	if ( commentSameTopicNotificationLabel != null ) { document.getElementById( "MCCommentSameTopicNotificationLabel" ).firstChild.nodeValue = commentSameTopicNotificationLabel; }
	
	var commentSameHelpSystemNotificationLabel	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "CommentSameHelpSystemNotificationLabel", null );
	if ( commentSameHelpSystemNotificationLabel != null ) { document.getElementById( "MCCommentSameHelpSystemNotificationLabel" ).firstChild.nodeValue = commentSameHelpSystemNotificationLabel; }
	
	this.MissingRequiredField	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "MissingRequiredField", this.MissingRequiredField );
	this.UpdateSuccess			= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "UpdateSuccess", this.UpdateSuccess );
};

CMCRegisterUserDialog.prototype.ItemsToXml	= function()
{
	var xmlDoc	= CMCXmlParser.CreateXmlDocument( "FeedbackUserProfile" );
	var root	= xmlDoc.documentElement;
	
	for ( var i = 0, length = this.mItemInfos.length; i < length; i++ )
	{
		var itemInfo	= this.mItemInfos[i];
		var name		= itemInfo.Name;
		var value		= FMCGetControl( itemInfo.ControlEl );
		var item		= xmlDoc.createElement( "Item" );
		
		item.setAttribute( "Name", name );
		item.setAttribute( "Value", value.toString() );
		
		root.appendChild( item );
	}
	
	return xmlDoc;
};

CMCRegisterUserDialog.prototype.Cancel	= function()
{
	CMCRegisterUserDialog.InCheckUserStatusMode = false;
};

CMCRegisterUserDialog.prototype.OK	= function()
{
	if ( CMCRegisterUserDialog.InCheckUserStatusMode )
	{
		return true;
	}

	if ( this.mDialogMode == CMCRegisterUserDialog.DialogMode.NewUserProfile )
	{
		for ( var i = 0, length = this.mItemInfos.length; i < length; i++ )
		{
			var itemInfo	= this.mItemInfos[i];
			var name		= itemInfo.Name;
			var label		= CMCFlareStylesheet.LookupValue( "FeedbackUserProfileItem", name, "Label", name );
			var required	= null;
			
			if ( name == "Username" || name == "EmailAddress" || this.mVersion == 1 )
			{
				required = true;
			}
			else
			{
				required = FMCStringToBool( CMCFlareStylesheet.LookupValue( "FeedbackUserProfileItem", name, "Required", "false" ) );
			}

			if ( required && String.IsNullOrEmpty( itemInfo.ControlEl.value ) )
			{
				alert( this.MissingRequiredField + itemInfo.Label );
				return false;
			}
		}

		var el	= document.getElementById( "MCDialogSubmit" );
		el.disabled = true;
		
		CMCRegisterUserDialog.InCheckUserStatusMode = true;

		var xmlDoc	= this.ItemsToXml();
		
        if (this.mVersion == 1)
        {
            gServiceClient.StartActivateUser(xmlDoc, CMCRegisterUserDialog.StartActivateUserOnComplete, null);
        }
        else
        {
            gServiceClient.StartActivateUser2(xmlDoc, CMCRegisterUserDialog.StartActivateUserOnComplete, null);
        }

		var registrationSubmit		= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "RegistrationSubmit", this.RegistrationSubmit );
		var registrationSubmitNote	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "RegistrationSubmitNote", this.RegistrationSubmitNote );
		
		alert( registrationSubmit + "\r\n\r\n" + registrationSubmitNote + "\r\n" );
	}
	else if ( this.mDialogMode == CMCRegisterUserDialog.DialogMode.EditUserProfile )
	{
		var guid	= FMCLoadUserData( "LiveHelpUserGuid" );
		var xmlDoc	= this.ItemsToXml();
		
		gServiceClient.UpdateUserProfile( guid, xmlDoc, function ( result, args )
		{
			CMCRegisterUserDialog.InCheckUserStatusMode = true;
			
			if ( result == "00000000-0000-0000-0000-000000000000" )
			{
				alert( this.UpdateSuccess );
				
				var submitButton	= document.getElementById( "MCDialogSubmit" );
				CMCDialog.OK.call( submitButton );
			}
			else
			{
				var el	= document.getElementById( "MCDialogSubmit" );
				el.disabled = true;
				
				CMCRegisterUserDialog.InCheckUserStatusMode = true;

				FMCSaveUserData( "LiveHelpPendingGuid", result );
				FMCRemoveUserData( "LiveHelpUserGuid", result );
				
				gServiceClient.CheckUserStatus( result, CMCRegisterUserDialog.CheckUserStatusOnComplete, null );
				
				var registrationSubmit		= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "RegistrationSubmit", this.RegistrationSubmit );
				var registrationSubmitNote	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "RegistrationSubmitNote", this.RegistrationSubmitNote );
				
				alert( registrationSubmit + "\r\n\r\n" + registrationSubmitNote + "\r\n" );
			}
		}, null, this );
	}
	
	this.SaveValues();
	
	return false;
};

CMCRegisterUserDialog.prototype.SaveValues	= function()
{
	for ( var i = 0, length = this.mItemInfos.length; i < length; i++ )
	{
		var itemInfo	= this.mItemInfos[i];
		var name		= itemInfo.Name;
		var value		= FMCGetControl( itemInfo.ControlEl );

		if ( !String.IsNullOrEmpty( value ) )
		{
			FMCSaveUserData( name, value );
		}
	}
};

CMCRegisterUserDialog.IsV1Item	= function( item )
{
	return (item == "Username" || item == "EmailAddress" || item == "FirstName" || item == "LastName" || item == "Country" || item == "PostalCode" || item == "Gender" );
};

CMCRegisterUserDialog.LookupV1Style	= function( item )
{
	var val = null;
	
	if ( item == "Username" )
	{
		val = CMCFlareStylesheet.LookupValue( "Dialog", "RegisterUser", "UserNameLabel", null );
	}
	else if ( item == "GenderFemaleName" || item == "GenderMaleName" )
	{
		val = CMCFlareStylesheet.LookupValue( "Dialog", "RegisterUser", item, null );
	}
	else
	{
		val = CMCFlareStylesheet.LookupValue( "Dialog", "RegisterUser", item + "Label", null );
	}
	
	return val;
};

CMCRegisterUserDialog.LookupDefaultStyleValue	= function( item )
{
	if ( item == "Username" )
	{
		return "Username";
	}
	else if ( item == "EmailAddress" )
	{
		return "E-mail Address";
	}
	else if ( item == "FirstName" )
	{
		return "First Name";
	}
	else if ( item == "LastName" )
	{
		return "Last Name";
	}
	else if ( item == "Country" )
	{
		return "Country";
	}
	else if ( item == "PostalCode" )
	{
		return "Postal Code";
	}
	else if ( item == "Gender" )
	{
		return "Gender";
	}
};

CMCRegisterUserDialog.StartActivateUserOnComplete	= function( pendingGuid, onCompleteArgs )
{
	if ( FMCIsHtmlHelp() )
	{
		// Doing FMCRegisterCallback() for "persistence" frame isn't necessary since it was done before this point is reached
		
		FMCSaveUserData( "LiveHelpPendingGuid", pendingGuid );
	}
	else
	{
		FMCSetCookie( "LiveHelpPendingGuid", pendingGuid, 36500 );
	}
	
	//
	
	if ( CMCRegisterUserDialog.InCheckUserStatusMode )
	{
		gServiceClient.CheckUserStatus( pendingGuid, CMCRegisterUserDialog.CheckUserStatusOnComplete, null );
	}
};

CMCRegisterUserDialog.CheckUserStatusOnComplete	= function( status, onCompleteArgs )
{
	if ( CMCRegisterUserDialog.InCheckUserStatusMode )
	{
		if ( status == "Pending" )
		{
			setTimeout( CMCRegisterUserDialog.CheckUserStatus, 5000 );
		}
		else
		{
			if ( FMCIsHtmlHelp() )
			{
				// Doing FMCRegisterCallback() for "persistence" frame isn't necessary since it was done before this point is reached
				
				FMCRemoveUserData( "LiveHelpPendingGuid", null );
				FMCSaveUserData( "LiveHelpUserGuid", status );
			}
			else
			{
				FMCRemoveCookie( "LiveHelpPendingGuid" );
				FMCSetCookie( "LiveHelpUserGuid", status, 36500 );
			}

			var submitButton	= document.getElementById( "MCDialogSubmit" );
			CMCDialog.OK.call( submitButton );
		}
	}
};

CMCRegisterUserDialog.InCheckUserStatusMode	= false;

CMCRegisterUserDialog.CheckUserStatus	= function()
{
	if ( !CMCRegisterUserDialog.InCheckUserStatusMode )
	{
		return;
	}
	
	//
	
	var pendingGuid	= null;
	
	if ( FMCIsHtmlHelp() )
	{
		// Doing FMCRegisterCallback() for "persistence" frame isn't necessary since it was done before this point is reached

		pendingGuid = FMCLoadUserData( "LiveHelpPendingGuid" );
	}
	else
	{
		pendingGuid = FMCReadCookie( "LiveHelpPendingGuid" );
	}
	
	gServiceClient.CheckUserStatus( pendingGuid, CMCRegisterUserDialog.CheckUserStatusOnComplete, null );
};

//
//    End class CMCRegisterUserDialog
//

//
//    Class CMCItemInfo
//

function CMCItemInfo( name, label, controlEl, required )
{
	this.Name = name;
	this.Label = label;
	this.ControlEl = controlEl;
	this.Required = required;
}

//
//    End class CMCItemInfo
//
