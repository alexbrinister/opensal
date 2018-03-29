// {{MadCap}} //////////////////////////////////////////////////////////////////
// Copyright: MadCap Software, Inc - www.madcapsoftware.com ////////////////////
////////////////////////////////////////////////////////////////////////////////
// <version>6.1.0.0</version>
////////////////////////////////////////////////////////////////////////////////

//
//    Class CMCAddCommentDialog
//

function CMCAddCommentDialog( winNode, anonymousEnabled )
{
	CMCDialog.call( this, winNode );
	
	// Public properties
	
	this.mAnonymousEnabled = anonymousEnabled;
	
	// Overridden properties
	
	this.StyleClass			= "AddComment";
	this.FontFamily			= "Arial";
	this.FontSize			= "12px";
	this.FontWeight			= "normal";
	this.FontStyle			= "normal";
	this.Color				= "#000000";
	this.TitleLabel			= "Add Comment:";
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
	
	this.UserNameLabel		= "User Name:";
	this.SubjectLabel		= "Subject:";
	this.CommentLabel		= "Comment:";
	
	this.CommentLengthExceeded = "The maximum comment length was exceeded by {n} characters.";
}

CMCAddCommentDialog.prototype = new CMCDialog();
CMCAddCommentDialog.prototype.constructor = CMCAddCommentDialog;
CMCAddCommentDialog.prototype.base = CMCDialog.prototype;

CMCAddCommentDialog.prototype.InnerHtml =	"" +
//											"<div id=\"AddCommentDialog\" style=\"display: none;\">" +
//												"<div id=\"MCDialogTitle\" style=\"font-size: 14px; font-weight: bold; font-variant: small-caps;\">" +
//												"</div>" +
//												"" +
//												"<br />" +
//												"" +
												"<table class=\"MCDialogOuterTable\">" +
													"<col style=\"width: 100px;\" />" +
													"<col style=\"width: auto;\" />" +
													"<tr>" +
														"<td id=\"MCUserNameLabel\" class=\"Label\">User Name:</td>" +
														"<td>" +
															"<input id=\"MCUsername\" type=\"text\" style=\"width: 200px;\" maxlength=\"50\" />" +
														"</td>" +
													"</tr>" +
													"<tr>" +
														"<td id=\"MCSubjectLabel\" class=\"Label\">Subject:</td>" +
														"<td>" +
															"<input id=\"MCSubject\" type=\"text\" style=\"width: 200px;\" maxlength=\"100\" />" +
														"</td>" +
													"</tr>" +
													"<tr>" +
														"<td id=\"MCCommentLabel\" class=\"Label\">Comment:</td>" +
														"<td style=\"padding-right: 10px;\">" +
															"<textarea id=\"MCComment\" cols=\"35\" rows=\"8\" style=\"width: 100%;\"></textarea>" +
														"</td>" +
													"</tr>" +
												"</table>" +
												"" +
												"<div style=\"text-align: right; margin-top: 20px;\">" +
													"<input id=\"MCDialogSubmit\" type=\"Submit\" value=\"Submit\" />" +
													"<input id=\"MCDialogCancel\" type=\"button\" value=\"Cancel\" />" +
												"</div>";
//											"</div>";

CMCAddCommentDialog.prototype.OnInitializing	= function()
{
	this.base.OnInitializing.call( this );
	
	var commentNode	= this.mWindow.document.getElementById( "MCComment" );
	
	if ( commentNode.firstChild )
	{
		commentNode.removeChild( commentNode.firstChild );
	}
	
	if ( this.mAnonymousEnabled )
	{
		var username	= null;
		
		if ( FMCIsHtmlHelp() )
		{
			// Doing FMCRegisterCallback() for "persistence" frame isn't necessary since it was done before this point is reached

			username = FMCLoadUserData( "LiveHelpUsername" );
		}
		else
		{
			username = FMCReadCookie( "LiveHelpUsername" );
		}
		
		if ( username )
		{
			this.mWindow.document.getElementById( "MCUsername" ).value = username;
			this.mWindow.document.getElementById( "MCSubject" ).focus();
		}
		else
		{
			this.mWindow.document.getElementById( "MCUsername" ).focus();
		}
	}
	else
	{
		var tr	= this.mWindow.document.getElementById( "MCUsername" ).parentNode.parentNode;
		
		tr.parentNode.removeChild( tr );
		
		this.mWindow.document.getElementById( "MCSubject" ).focus();
	}
};

CMCAddCommentDialog.prototype.LoadStyles	= function()
{
	this.base.LoadStyles.call( this );
	
	var userNameLabel	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "UserNameLabel", this.UserNameLabel );
	var subjectLabel	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "SubjectLabel", this.SubjectLabel );
	var commentLabel	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "CommentLabel", this.CommentLabel );
	
	document.getElementById( "MCUserNameLabel" ).firstChild.nodeValue = userNameLabel;
	document.getElementById( "MCSubjectLabel" ).firstChild.nodeValue = subjectLabel;
	document.getElementById( "MCCommentLabel" ).firstChild.nodeValue = commentLabel;
	
	this.CommentLengthExceeded = CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "CommentLengthExceeded", this.CommentLengthExceeded );
};

CMCAddCommentDialog.prototype.OK	= function()
{
	var topicID		= FMCGetMCAttribute( this.mWindow.document.documentElement, "MadCap:liveHelp" );
	var userGuid	= null;
	
	if ( FMCIsHtmlHelp() )
	{
		// Doing FMCRegisterCallback() for "persistence" frame isn't necessary since it was done before this point is reached

		userGuid = FMCLoadUserData( "LiveHelpUserGuid" );
	}
	else
	{
		userGuid = FMCReadCookie( "LiveHelpUserGuid" );
	}
	
	var username	= null;
	
	if ( this.mAnonymousEnabled )
	{
		username = this.mWindow.document.getElementById( "MCUsername" ).value;
		
		if ( username == null || username.length == 0 )
		{
			alert( "Please enter a user name." );
			return false;
		}
		
		if ( FMCIsHtmlHelp() )
		{
			// Doing FMCRegisterCallback() for "persistence" frame isn't necessary since it was done before this point is reached
			
			FMCSaveUserData( "LiveHelpUsername", username );
		}
		else
		{
			FMCSetCookie( "LiveHelpUsername", username, 36500 );
		}
	}

	var subject		= this.mWindow.document.getElementById( "MCSubject" ).value;
	var comment		= this.mWindow.document.getElementById( "MCComment" ).value;
	
	if ( subject == null || subject.length == 0 )
	{
		alert( "Please enter a subject." );
		return false;
	}
	else if ( comment == null || comment.length == 0 )
	{
		alert( "Please enter a comment." );
		return false;
	}
	
	try
	{
		gServiceClient.AddComment( topicID, userGuid, username, subject, comment, null );
	}
	catch ( ex )
	{
		var message = this.CommentLengthExceeded.replace( /{n}/g, ex.Data.ExceedAmount );
		alert( message );
		
		return false;
	}
	
	return true;
};

CMCAddCommentDialog.prototype.Cancel	= function()
{
};

//
//    End class CMCAddCommentDialog
//
