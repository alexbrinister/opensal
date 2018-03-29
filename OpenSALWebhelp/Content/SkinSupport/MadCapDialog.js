/// <reference path="MadCapUtilities.js" />

// {{MadCap}} //////////////////////////////////////////////////////////////////
// Copyright: MadCap Software, Inc - www.madcapsoftware.com ////////////////////
////////////////////////////////////////////////////////////////////////////////
// <version>6.1.0.0</version>
////////////////////////////////////////////////////////////////////////////////

//
//    Class CMCDialog
//

function CMCDialog( winNode )
{
	// Public properties
	
	this.mRootEl		= null;
	this.mIndex			= -1;
	this.mOK			= false;
	this.mOnCloseFunc	= null;
	this.mOnCloseArgs	= null;
	
	this.mWindow		= winNode;
	
	// Overridable properties
	
	this.StyleClass		= "Dialog";

    // Public member functions
}

CMCDialog.prototype.Run	= function( onCloseFunc, onCloseArgs )
{
	FMCInsertOpacitySheet( this.mWindow, "Gray" );
	
	//

	CMCDialog.Dialogs.push( this );

	this.mIndex = CMCDialog.Dialogs.length - 1;
	
	//
	
	if ( onCloseFunc )
	{
		this.mOnCloseFunc = onCloseFunc;
		this.mOnCloseArgs = onCloseArgs;
	}
	
	//
	
	var wrapperDiv	= this.mWindow.document.createElement( "div" );
	this.RootEl = wrapperDiv;
	
	wrapperDiv.setAttribute( "MadCap:dialogIndex", this.mIndex );
	wrapperDiv.id = "MCDialog_" + this.mIndex;
	wrapperDiv.className = "MCDialogWrapper";
	wrapperDiv.style.display = "none";
	
	if ( FMCIsQuirksMode( this.mWindow ) )
	{
		wrapperDiv.style.position = "absolute";
	}
	
	var dialogDiv	= this.mWindow.document.createElement( "div" );
	
	dialogDiv.className = "MCDialog";
	dialogDiv.innerHTML = this.InnerHtml;
	
	wrapperDiv.appendChild( dialogDiv );
	
	var titleDiv	= this.mWindow.document.createElement( "div" );
	
	titleDiv.id = "MCDialogTitle";
	titleDiv.appendChild( this.mWindow.document.createTextNode( "" ) );
	
	dialogDiv.insertBefore( titleDiv, dialogDiv.firstChild );
	dialogDiv.insertBefore( this.mWindow.document.createElement( "br" ), titleDiv.nextSibling );
	this.mWindow.document.body.appendChild( wrapperDiv );

	var submitButton	= document.getElementById( "MCDialogSubmit" );
	submitButton.onclick = CMCDialog.OK;
	
	var cancelButton	= document.getElementById( "MCDialogCancel" );
	cancelButton.onclick = CMCDialog.Cancel;
	
	//
	
	var shadowDiv	= this.mWindow.document.createElement( "div" );
	shadowDiv.id = "MCDialog_DropShadow";
	shadowDiv.className = "MCDialogShadow";
	
	wrapperDiv.appendChild( shadowDiv );
	
	//
	
	this.Create();
	
	//

	this.LoadStyles();

	//

	wrapperDiv.style.display = "";
	shadowDiv.style.display = "";
	
	//
	
	this.OnInitializing();
	
	//

	var height	= dialogDiv.offsetHeight;

	// If the browser is in strict mode or it's in quirks mode but not IE, the height will already include border and padding widths. Otherwise, manually account for them below.

	if ( !FMCIsQuirksMode( this.mWindow ) || !this.mWindow.document.body.currentStyle )
	{
		height -= parseInt( FMCGetComputedStyle( dialogDiv, "borderTopWidth" ) );
		height -= parseInt( FMCGetComputedStyle( dialogDiv, "borderBottomWidth" ) );
		height -= parseInt( FMCGetComputedStyle( dialogDiv, "paddingTop" ) );
		height -= parseInt( FMCGetComputedStyle( dialogDiv, "paddingBottom" ) );
	}

	shadowDiv.style.height = height + "px";

	wrapperDiv.style.left = ((FMCGetClientWidth( this.mWindow, false ) / 2) - 200) + "px";
	wrapperDiv.style.top = ((FMCGetClientHeight( this.mWindow, false ) / 2) - 200) + "px";

	var shadowOpacity	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "ShadowOpacity", this.ShadowOpacity );

	MCFader.FadeIn( dialogDiv, 0, 100, shadowDiv, 0, shadowOpacity, false );
};

CMCDialog.prototype.Create	= function()
{
};

CMCDialog.prototype.OnInitializing	= function()
{
};

CMCDialog.prototype.LoadStyles	= function()
{
	var titleNode	= this.mWindow.document.getElementById( "MCDialogTitle" );

	titleNode.firstChild.nodeValue	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "TitleLabel", this.TitleLabel );
	titleNode.style.fontFamily		= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "TitleFontFamily", this.TitleFontFamily );
	titleNode.style.fontSize		= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "TitleFontSize", this.TitleFontSize );
	titleNode.style.fontWeight		= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "TitleFontWeight", this.TitleFontWeight );
	titleNode.style.fontStyle		= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "TitleFontStyle", this.TitleFontStyle );
	titleNode.style.fontVariant		= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "TitleFontVariant", this.TitleFontVariant );
	titleNode.style.color			= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "TitleColor", this.TitleColor );
	
	//
	
	var submitButton	= this.mWindow.document.getElementById( "MCDialogSubmit" );
	submitButton.value = CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "SubmitButtonLabel", this.SubmitButtonLabel );
	
	var cancelButton	= this.mWindow.document.getElementById( "MCDialogCancel" );
	cancelButton.value = CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "CancelButtonLabel", this.CancelButtonLabel );
	
	//

	var div	= document.getElementById( "MCDialog_" + this.mIndex ).firstChild;
	
	// While topics are in quirks mode, do this.SetLabelStyles()

//	div.style.fontFamily	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "FontFamily", this.FontFamily );
//	div.style.fontSize		= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "FontSize", this.FontSize );
//	div.style.fontWeight	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "FontWeight", this.FontWeight );
//	div.style.fontStyle		= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "FontStyle", this.FontStyle );
//	div.style.color			= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "Color", this.Color );

	this.SetLabelStyles( div );

	//
	
	div.style.backgroundColor = CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "BackgroundColor", this.BackgroundColor );
	
	var borderLeft		= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "BorderLeft", this.BorderLeft );
	var borderRight		= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "BorderRight", this.BorderRight );
	var borderTop		= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "BorderTop", this.BorderTop );
	var borderBottom	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "BorderBottom", this.BorderBottom );
	
	div.style.borderLeft = borderLeft;
	div.style.borderRight = borderRight;
	div.style.borderTop = borderTop;
	div.style.borderBottom = borderBottom;
	
	//
	
	var shadowDiv		= this.mWindow.document.getElementById( "MCDialog_DropShadow" );
	var shadowBgColor	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "ShadowColor", this.ShadowColor );
	
	shadowDiv.style.backgroundColor = shadowBgColor;
	
	var shadowDistance	= parseInt( CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "ShadowDistance", this.ShadowDistance ) );
	
	shadowDiv.style.top = shadowDistance + "px";
	shadowDiv.style.left = shadowDistance + "px";
	shadowDiv.style.borderLeftWidth = FMCGetComputedStyle( div, "borderLeftWidth" );
	shadowDiv.style.borderRightWidth = FMCGetComputedStyle( div, "borderRightWidth" );
	shadowDiv.style.borderTopWidth = FMCGetComputedStyle( div, "borderTopWidth" );
	shadowDiv.style.borderBottomWidth = FMCGetComputedStyle( div, "borderBottomWidth" );
	shadowDiv.style.borderLeftColor = shadowBgColor;
	shadowDiv.style.borderLeftStyle = "solid";
	shadowDiv.style.borderRightColor = shadowBgColor;
	shadowDiv.style.borderRightStyle = "solid";
	shadowDiv.style.borderTopColor = shadowBgColor;
	shadowDiv.style.borderTopStyle = "solid";
	shadowDiv.style.borderBottomColor = shadowBgColor;
	shadowDiv.style.borderBottomStyle = "solid";
};

CMCDialog.prototype.SetLabelStyles	= function( el )
{
	if ( el.className == "Label" )
	{
		el.style.fontFamily	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "FontFamily", this.FontFamily );
		el.style.fontSize	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "FontSize", this.FontSize );
		el.style.fontWeight	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "FontWeight", this.FontWeight );
		el.style.fontStyle	= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "FontStyle", this.FontStyle );
		el.style.color		= CMCFlareStylesheet.LookupValue( "Dialog", this.StyleClass, "Color", this.Color );
	}
	
	var childNodes	= el.childNodes;
	var length		= el.childNodes.length;
	
	for ( var i = 0; i < length; i++ )
	{
		var node	= childNodes[i];
		
		this.SetLabelStyles( node );
	}
};

CMCDialog.GetDialog	= function( el )
{
	var index	= CMCDialog.GetDialogIndex( el );
	var dlg		= CMCDialog.Dialogs[index];
	
	return dlg;
}

CMCDialog.GetDialogIndex	= function( el )
{
	var index	= -1;
	var id		= el.id;
	
	if ( id != null && id.substring( 0, "MCDialog_".length ) == "MCDialog_" )
	{
		index = FMCGetAttributeInt( el, "MadCap:dialogIndex", -1 );
	}
	else
	{
		index = CMCDialog.GetDialogIndex( el.parentNode );
	}
	
	return index;
}

CMCDialog.DoesDialogExist	= function()
{
	var dialogs = CMCDialog.Dialogs;
	
	for ( var i = 0, length = dialogs.length; i < length; i++ )
	{
		if ( dialogs[i] != null )
		{
			return true;
		}
	}
	
	return false;
}

//CMCDialog.DoesDialogTypeExist	= function( type )
//{
//	var dialogs = CMCDialog.Dialogs;
//	
//	for ( var i = 0, length = dialogs.length; i < length; i++ )
//	{
//		if ( dialogs[i].constructor == type )
//		{
//			return true;
//		}
//	}
//	
//	return false;
//}

CMCDialog.OK	= function( e )
{
	var dlg	= CMCDialog.GetDialog( this );
	
	//
	
	if ( dlg.OK() )
	{
		dlg.mOK = true;
		CMCDialog.Close( this );
	}
}

CMCDialog.Cancel	= function( e )
{
	var dlg	= CMCDialog.GetDialog( this );
	
	//
	
	dlg.Cancel();
	
	CMCDialog.Close( this );
}

CMCDialog.Close	= function( el )
{
	var index	= CMCDialog.GetDialogIndex( el );
	var dlg		= CMCDialog.Dialogs[index];
	
	//
	
	var wrapperDiv	= dlg.mWindow.document.getElementById( "MCDialog_" + dlg.mIndex );
	wrapperDiv.parentNode.removeChild( wrapperDiv );
			
	//
	
	CMCDialog.Dialogs[index] = null;
	
	FMCRemoveOpacitySheet( dlg.mWindow );
	
	if ( dlg.mOK && dlg.mOnCloseFunc != null )
	{
		dlg.mOnCloseFunc( dlg.mOnCloseArgs );
	}
}

CMCDialog.Dialogs	= new Array();

//
//    End class CMCDialog
//
