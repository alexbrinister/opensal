/// <reference path="MadCapUtilities.js" />
/// <reference path="MadCapRegisterUserDialog.js" />

// {{MadCap}} //////////////////////////////////////////////////////////////////
// Copyright: MadCap Software, Inc - www.madcapsoftware.com ////////////////////
////////////////////////////////////////////////////////////////////////////////
// <version>6.1.0.0</version>
////////////////////////////////////////////////////////////////////////////////

function FMCOpenCommentDialog( reply, comment, parentCommentID )
{
	var xmlDoc		= CMCXmlParser.GetXmlDoc( MCGlobals.RootFolder + MCGlobals.SubsystemFile, false, null, null );
	var projectID	= xmlDoc.documentElement.getAttribute( "LiveHelpOutputId" );
	
	gServiceClient.GetAnonymousEnabled( projectID, FMCGetAnonymousEnabledOnComplete, [reply, comment, parentCommentID] );
}

function FMCGetAnonymousEnabledOnComplete( enabled, onCompleteArgs )
{
	var reply			= onCompleteArgs[0];
	var comment			= onCompleteArgs[1];
	var parentCommentID	= onCompleteArgs[2];
	
	if ( FMCIsHtmlHelp() )
	{
		onCompleteArgs.push( enabled );
		
		FMCRegisterCallback( "Persistence", MCEventType.OnInit, function( args )
		{
			var reply				= args[0];
			var comment				= args[1];
			var parentCommentID		= args[2];
			var anonymousEnabled	= args[3];
			
			if ( anonymousEnabled )
			{
				FMCRunCommentDialog( anonymousEnabled, reply, comment, parentCommentID );
			}
			else
			{
				var userGuid	= FMCLoadUserData( "LiveHelpUserGuid" );
				
				if ( userGuid == null )
				{
					gServiceClient.GetVersion( function( version )
					{
						var dlg	= new CMCRegisterUserDialog( window, CMCRegisterUserDialog.DialogMode.NewUserProfile, version );

						dlg.Run( FMCRegisterUserDialogOnClose, args );
					}, null, null );
				}
				else
				{
					FMCRunCommentDialog( anonymousEnabled, reply, comment, parentCommentID );
				}
			}
		},
		onCompleteArgs );

		return;
	}
	
	if ( !enabled )
	{
		var userGuid	= FMCReadCookie( "LiveHelpUserGuid" );

		if ( userGuid == null )
		{
			gServiceClient.GetVersion( function( version )
			{
				var dlg	= new CMCRegisterUserDialog( window, CMCRegisterUserDialog.DialogMode.NewUserProfile, version );

				dlg.Run( FMCRegisterUserDialogOnClose, onCompleteArgs );
			}, null, null );
		}
		else
		{
			FMCRunCommentDialog( enabled, reply, comment, parentCommentID );
		}
	}
	else
	{
		FMCRunCommentDialog( enabled, reply, comment, parentCommentID );
	}
}

function FMCRegisterUserDialogOnClose( onCloseArgs )
{
	var reply			= onCloseArgs[0];
	var comment			= onCloseArgs[1];
	var parentCommentID	= onCloseArgs[2];
	
	FMCRunCommentDialog( false, reply, comment, parentCommentID );
}

function FMCRunCommentDialog( anonymousEnabled, reply, comment, parentCommentID )
{
	if ( MCGlobals.BodyFrame.CMCDialog.DoesDialogExist() )
	{
		return;
	}
	
	var dlg = null;
	
	if ( !reply )
	{
		dlg = new CMCAddCommentDialog( window, anonymousEnabled );
	}
	else
	{
		dlg = new CMCReplyCommentDialog( window, anonymousEnabled, comment, parentCommentID );
	}
	
	dlg.Run( function() {
		if ( MCGlobals.BodyCommentsFrame != null )
		{
			MCGlobals.BodyCommentsFrame.TopicComments_RefreshComments();
		}
	}, null );
}

function FMCGetRatingOnComplete( averageRating, ratingCount )
{
	var avgRatingIcons	= document.getElementById( "MCAverageRatingIcons" );
	var ratingCountSpan	= document.getElementById( "MCRatingCount" );
	var textNode		= ratingCountSpan.childNodes[0];
	
	if ( !textNode )
	{
		textNode = ratingCountSpan.appendChild( document.createTextNode( "" ) );
	}
	
	textNode.nodeValue = " based on " + ratingCount + " ratings";
	avgRatingIcons.title = "Topic rating: " + averageRating + "%";
	
	FMCDrawRatingIcons( averageRating, avgRatingIcons );

	//

	var loadingImg	= document.getElementById( "MCLoadingImage" );
	loadingImg.parentNode.removeChild( loadingImg );
}

function FMCEditUserProfile()
{
	if ( MCGlobals.BodyFrame.CMCDialog.DoesDialogExist() )
	{
		return;
	}
	
	var xmlDoc		= CMCXmlParser.GetXmlDoc( MCGlobals.RootFolder + MCGlobals.SubsystemFile, false, null, null );
	var projectID	= xmlDoc.documentElement.getAttribute( "LiveHelpOutputId" );
	
	gServiceClient.GetAnonymousEnabled( projectID, GetAnonymousEnabledOnComplete, null );

	function GetAnonymousEnabledOnComplete( enabled, onCompleteArgs )
	{
		if ( FMCIsHtmlHelp() )
		{
			FMCRegisterCallback( "Persistence", MCEventType.OnInit, PersistenceInitialized, null );

			return;
		}
		
		PersistenceInitialized( null );

		function PersistenceInitialized( args )
		{
			if ( !enabled )
			{
				var userGuid	= FMCLoadUserData( "LiveHelpUserGuid" );
				
				gServiceClient.GetVersion( function( version )
				{
					if ( userGuid == null )
					{
						var dlg	= new CMCRegisterUserDialog( window, CMCRegisterUserDialog.DialogMode.NewUserProfile, version );

						dlg.Run( null, null );
					}
					else
					{
						if ( version == 1 )
						{
							alert( "The Feedback Server you are connecting to does not support this feature." );
							return;
						}
						
						var dlg	= new CMCRegisterUserDialog( window, CMCRegisterUserDialog.DialogMode.EditUserProfile, version );

						dlg.Run( null, null );
					}
				}, null, null );
			}
		}
	}
}

if ( gRuntimeFileType == "Topic" )
{
}
