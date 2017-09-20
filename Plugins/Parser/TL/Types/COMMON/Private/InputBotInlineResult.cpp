#include "../Public/InputBotInlineResult.h"


//begin namespace block
namespace COMMON
{

InputBotInlineResult::InputBotInlineResult()
{
	this->_ConstructorID = 1524742956;
}

InputBotInlineResult::InputBotInlineResult(FString id, FString type, FString title, FString description, FString url, FString thumb_url, FString content_url, FString content_type, int32 w, int32 h, int32 duration, PRIVATE::InputBotInlineMessage* send_message)
{
	this->_ConstructorID = 1524742956;
	this->id = id;
	this->type = type;
	this->title = title;
	this->description = description;
	this->url = url;
	this->thumb_url = thumb_url;
	this->content_url = content_url;
	this->content_type = content_type;
	this->w = w;
	this->h = h;
	this->duration = duration;
	this->send_message = send_message;
}
void InputBotInlineResult::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!title.IsEmpty())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!description.IsEmpty())
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(!url.IsEmpty())
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(!thumb_url.IsEmpty())
	{
		Flags |= (1 << 4);
	}
	else
	{
		Flags |= 0;
	}
	if(!content_url.IsEmpty())
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	if(!content_type.IsEmpty())
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	if(!w)
	{
		Flags |= (1 << 6);
	}
	else
	{
		Flags |= 0;
	}
	if(!h)
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
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->id);
	Writer.TGWriteString(this->type);
	Writer.TGWriteString(this->title);
	Writer.TGWriteString(this->description);
	Writer.TGWriteString(this->url);
	Writer.TGWriteString(this->thumb_url);
	Writer.TGWriteString(this->content_url);
	Writer.TGWriteString(this->content_type);
	if(!this->w)
	{
	Writer.WriteInt(this->w);
	}
	if(!this->h)
	{
	Writer.WriteInt(this->h);
	}
	if(!this->duration)
	{
	Writer.WriteInt(this->duration);
	}
	this->send_message->OnSend(Writer);
}


void InputBotInlineResult::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	id = Reader.TGReadString();
	type = Reader.TGReadString();
	if((Flags & (1 << 1)) != 0) 
	{
	title = Reader.TGReadString();
	}
	if((Flags & (1 << 2)) != 0) 
	{
	description = Reader.TGReadString();
	}
	if((Flags & (1 << 3)) != 0) 
	{
	url = Reader.TGReadString();
	}
	if((Flags & (1 << 4)) != 0) 
	{
	thumb_url = Reader.TGReadString();
	}
	if((Flags & (1 << 5)) != 0) 
	{
	content_url = Reader.TGReadString();
	}
	if((Flags & (1 << 5)) != 0) 
	{
	content_type = Reader.TGReadString();
	}
	if((Flags & (1 << 6)) != 0) 
	{
	w = Reader.ReadInt();
	}
	if((Flags & (1 << 6)) != 0) 
	{
	h = Reader.ReadInt();
	}
	if((Flags & (1 << 7)) != 0) 
	{
	duration = Reader.ReadInt();
	}
	send_message = reinterpret_cast<PRIVATE::InputBotInlineMessage*>(Reader.TGReadObject());
}
InputBotInlineResult::~InputBotInlineResult()
{

}
}//end namespace block
