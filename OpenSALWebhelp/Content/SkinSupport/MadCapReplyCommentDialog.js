// {{MadCap}} //////////////////////////////////////////////////////////////////
// Copyright: MadCap Software, Inc - www.madcapsoftware.com ////////////////////
////////////////////////////////////////////////////////////////////////////////
// <version>6.1.0.0</version>
////////////////////////////////////////////////////////////////////////////////

//
//    Class CMCReplyCommentDialog
//

function CMCReplyCommentDialog( winNode, anonymousEnabled, comment, parentCommentID )
{
	CMCDialog.call( this, winNode );

	// Public properties

	this.mAnonymousEnabled	= anonymousEnabled;
	this.mComment			= comment;
	this.mParentCommentID	= parentCommentID;

	// Overridden properties

	this.StyleClass			= "ReplyComment";
	this.FontFamily			= "Arial";
	this.FontSize			= "12px";
	this.FontWeight			= "normal";
	this.FontStyle			= "normal";
	this.Color				= "#000000";
	this.TitleLabel			= "Reply to Comment:";
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
	
	this.UserNameLabel			= "User Name:";
	this.SubjectLabel			= "Subject:";
	this.CommentLabel			= "Comment:";
	this.OriginalCommentLabel	= "Original Comment:";
	
	this.CommentLengthExceeded = "The maximum comment length was exceeded by {n} characters.";
}

CMCReplyCommentDialog.prototype = new CMCDialog();
CMCReplyCommentDialog.prototype.constructor = CMCReplyCommentDialog;
CMCReplyCommentDialog.prototype.base = CMCDialog.prototype;

CMCReplyCommentDialog.prototype.InnerHtml =	"" +
//											"<div id=\"ReplyCommentDialog\" style=\"display: none;\">" +
//												"<div style=\"font-size: 14px; font-weight: bold; font-variant: small-caps;\">" +
//													"Reply to Comment:" +
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
															"<input id=\"MCUsername\" type=\"text\" style=\"width: 200px;\" />" +
														"</td>" +
													"</tr>" +
													"<tr>" +
														"<td id=\"MCSubjectLabel\" class=\"Label\">Subject:</td>" +
														"<td>" +
															"<input id=\"MCSubject\" type=\"text\" style=\"width: 200px;\" />" +
														"</td>" +
													"</tr>" +
													"<tr>" +
														"<td id=\"MCCommentLabel\" class=\"Label\">Comment:</td>" +
														"<td style=\"padding-right: 10px;\">" +
															"<textarea id=\"MCComment\" cols=\"35\" rows=\"8\" style=\"width: 100%;\"></textarea>" +
														"</td>" +
													"</tr>" +
													"<tr>" +
														"<td id=\"MCOriginalCommentLabel\" class=\"Label\">Original Comment:</td>" +
														"<td style=\"padding-right: 10px;\">" +
															"<textarea id=\"MCOriginalComment\" cols=\"35\" rows=\"5\" style=\"width: 100%;\" disabled=\"true\"></textarea>" +
														"</td>" +
													"</tr>" +
												"</table>" +
												"" +
												"<div style=\"text-align: right; margin-top: 20px;\">" +
													"<input id=\"MCDialogSubmit\" type=\"Submit\" value=\"Submit\" />" +
													"<input id=\"MCDialogCancel\" type=\"button\" value=\"Cancel\" />" +
												"</div>";
//											"</div>";

CMCReplyCommentDialog.prototype.OnInitializing	= function()
{
	this.base.OnInitializing.call( this );
	
	var commentNode	= this.mWindow.document.getElementById( "MCComment" );
	
	if ( commentNode.firstChild )
	{
		commentNode.removeChild( commentNode.firstChild );
	}
	
	if ( this.mAnonymousEnabled )
	{
		this.mWindow.document.getElementById( "MCUsername" ).focus();
	}
	else
	{
		var tr	= this.mWindow.document.getElementById( "MCUsername" ).parentNode.parentNode;
		
		tr.parentNode.removeChild( tr );
		
		this.mWindow.document.getElementById( "MCSubject" ).focus();
	}

	this.mWindow.document.getElementById( "MCOriginalComment" ).value = this.mComment;
};

CMCReplyCommentDialog.prototype.LoadStyles	= function()
{
	this.base.LoadStyles.call( this );
	
	var userNameLabel			= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "UserNameLabel", this.UserNameLabel );
	var subjectLabel			= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "SubjectLabel", this.SubjectLabel );
	var commentLabel			= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "CommentLabel", this.CommentLabel );
	var originalCommentLabel	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "OriginalCommentLabel", this.OriginalCommentLabel );
	
	document.getElementById( "MCUserNameLabel" ).firstChild.nodeValue = userNameLabel;
	document.getElementById( "MCSubjectLabel" ).firstChild.nodeValue = subjectLabel;
	document.getElementById( "MCCommentLabel" ).firstChild.nodeValue = commentLabel;
	document.getElementById( "MCOriginalCommentLabel" ).firstChild.nodeValue = originalCommentLabel;
	
	this.CommentLengthExceeded = CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "CommentLengthExceeded", this.CommentLengthExceeded );
};

CMCReplyCommentDialog.prototype.OK	= function()
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
		gServiceClient.AddComment( topicID, userGuid, username, subject, comment, this.mParentCommentID );
	}
	catch ( ex )
	{
		var message = this.CommentLengthExceeded.replace( /{n}/g, ex.Data.ExceedAmount );
		alert( message );
		
		return false;
	}
	
	return true;
};

CMCReplyCommentDialog.prototype.Cancel	= function()
{
};

//
//    End class CMCReplyCommentDialog
//
