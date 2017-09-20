#include "../Public/WebPage.h"


//begin namespace block
namespace COMMON
{

WebPage::WebPage()
{
	this->_ConstructorID = -1129052321;
}

WebPage::WebPage(unsigned long long id, FString url, FString display_url, int32 hash, FString type, FString site_name, FString title, FString description, COMMON::Photo* photo, FString embed_url, FString embed_type, int32 embed_width, int32 embed_height, int32 duration, FString author, COMMON::Document* document, PRIVATE::Page* cached_page)
{
	this->_ConstructorID = -1129052321;
	this->id = id;
	this->url = url;
	this->display_url = display_url;
	this->hash = hash;
	this->type = type;
	this->site_name = site_name;
	this->title = title;
	this->description = description;
	this->photo = photo;
	this->embed_url = embed_url;
	this->embed_type = embed_type;
	this->embed_width = embed_width;
	this->embed_height = embed_height;
	this->duration = duration;
	this->author = author;
	this->document = document;
	this->cached_page = cached_page;
}
void WebPage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!type.IsEmpty())
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!site_name.IsEmpty())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!title.IsEmpty())
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(!description.IsEmpty())
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(!photo)
	{
		Flags |= (1 << 4);
	}
	else
	{
		Flags |= 0;
	}
	if(!embed_url.IsEmpty())
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	if(!embed_type.IsEmpty())
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	if(!embed_width)
	{
		Flags |= (1 << 6);
	}
	else
	{
		Flags |= 0;
	}
	if(!embed_height)
	{
		Flags |= (1 << 6);
	}
	else
	{
		Flags |= 0;
	}
	if(!duration)
	{
		Flags |= (1 << 7);
	}
	else
	{
		Flags |= 0;
	}
	if(!author.IsEmpty())
	{
		Flags |= (1 << 8);
	}
	else
	{
		Flags |= 0;
	}
	if(!document)
	{
		Flags |= (1 << 9);
	}
	else
	{
		Flags |= 0;
	}
	if(!cached_page)
	{
		Flags |= (1 << 10);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteLong(this->id);
	Writer.TGWriteString(this->url);
	Writer.TGWriteString(this->display_url);
	Writer.WriteInt(this->hash);
	Writer.TGWriteString(this->type);
	Writer.TGWriteString(this->site_name);
	Writer.TGWriteString(this->title);
	Writer.TGWriteString(this->description);
	if(!this->photo)
	{
	this->photo->OnSend(Writer);
	}
	Writer.TGWriteString(this->embed_url);
	Writer.TGWriteString(this->embed_type);
	if(!this->embed_width)
	{
	Writer.WriteInt(this->embed_width);
	}
	if(!this->embed_height)
	{
	Writer.WriteInt(this->embed_height);
	}
	if(!this->duration)
	{
	Writer.WriteInt(this->duration);
	}
	Writer.TGWriteString(this->author);
	if(!this->document)
	{
	this->document->OnSend(Writer);
	}
	if(!this->cached_page)
	{
	this->cached_page->OnSend(Writer);
	}
}


void WebPage::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	id = Reader.ReadLong();
	url = Reader.TGReadString();
	display_url = Reader.TGReadString();
	hash = Reader.ReadInt();
	if((Flags & (1 << 0)) != 0) 
	{
	type = Reader.TGReadString();
	}
	if((Flags & (1 << 1)) != 0) 
	{
	site_name = Reader.TGReadString();
	}
	if((Flags & (1 << 2)) != 0) 
	{
	title = Reader.TGReadString();
	}
	if((Flags & (1 << 3)) != 0) 
	{
	description = Reader.TGReadString();
	}
	if((Flags & (1 << 4)) != 0) 
	{
	photo = reinterpret_cast<COMMON::Photo*>(Reader.TGReadObject());
	}
	if((Flags & (1 << 5)) != 0) 
	{
	embed_url = Reader.TGReadString();
	}
	if((Flags & (1 << 5)) != 0) 
	{
	embed_type = Reader.TGReadString();
	}
	if((Flags & (1 << 6)) != 0) 
	{
	embed_width = Reader.ReadInt();
	}
	if((Flags & (1 << 6)) != 0) 
	{
	embed_height = Reader.ReadInt();
	}
	if((Flags & (1 << 7)) != 0) 
	{
	duration = Reader.ReadInt();
	}
	if((Flags & (1 << 8)) != 0) 
	{
	author = Reader.TGReadString();
	}
	if((Flags & (1 << 9)) != 0) 
	{
	document = reinterpret_cast<COMMON::Document*>(Reader.TGReadObject());
	}
	if((Flags & (1 << 10)) != 0) 
	{
	cached_page = reinterpret_cast<PRIVATE::Page*>(Reader.TGReadObject());
	}
}
WebPage::~WebPage()
{

}
}//end namespace block
