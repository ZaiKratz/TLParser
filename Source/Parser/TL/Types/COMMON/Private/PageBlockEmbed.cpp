#include "../Public/PageBlockEmbed.h"


//begin namespace block
namespace COMMON
{

PageBlockEmbed::PageBlockEmbed()
{
	this->_ConstructorID = -840826671;
}

PageBlockEmbed::PageBlockEmbed(bool full_width, bool allow_scrolling, FString url, FString html, unsigned long long poster_photo_id, int32 w, int32 h, TLBaseObject*  caption)
{
	this->_ConstructorID = -840826671;
	this->full_width = full_width;
	this->allow_scrolling = allow_scrolling;
	this->url = url;
	this->html = html;
	this->poster_photo_id = poster_photo_id;
	this->w = w;
	this->h = h;
	this->caption = caption;
}
void PageBlockEmbed::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(full_width)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(allow_scrolling)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(!url.IsEmpty())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!html.IsEmpty())
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(poster_photo_id)
	{
		Flags |= (1 << 4);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->url);
	Writer.TGWriteString(this->html);
	if(this->poster_photo_id)
	{
	Writer.WriteLong(this->poster_photo_id);
	}
	Writer.WriteInt(this->w);
	Writer.WriteInt(this->h);
	this->caption->OnSend(Writer);
}


void PageBlockEmbed::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		full_width = true;
	}
	if((Flags & (1 << 3)) != 0) 
	{
		allow_scrolling = true;
	}
	if((Flags & (1 << 1)) != 0) 
	{
	url = Reader.TGReadString();
	}
	if((Flags & (1 << 2)) != 0) 
	{
	html = Reader.TGReadString();
	}
	if((Flags & (1 << 4)) != 0) 
	{
	poster_photo_id = Reader.ReadLong();
	}
	w = Reader.ReadInt();
	h = Reader.ReadInt();
	caption = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
PageBlockEmbed::~PageBlockEmbed()
{
	if(this->caption)
	{
		delete this->caption;
	}
}
}//end namespace block
