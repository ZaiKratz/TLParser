#include "../Public/MessageFwdHeader.h"


//begin namespace block
namespace COMMON
{

MessageFwdHeader::MessageFwdHeader()
{
	this->_ConstructorID = -85986132;
}

MessageFwdHeader::MessageFwdHeader(int32 from_id, FDateTime date, int32 channel_id, int32 channel_post, FString post_author)
{
	this->_ConstructorID = -85986132;
	this->from_id = from_id;
	this->date = date;
	this->channel_id = channel_id;
	this->channel_post = channel_post;
	this->post_author = post_author;
}
void MessageFwdHeader::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(from_id)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(channel_id)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(channel_post)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(!post_author.IsEmpty())
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	if(this->from_id)
	{
	Writer.WriteInt(this->from_id);
	}
	Writer.TGWriteDate(this->date);
	if(this->channel_id)
	{
	Writer.WriteInt(this->channel_id);
	}
	if(this->channel_post)
	{
	Writer.WriteInt(this->channel_post);
	}
	Writer.TGWriteString(this->post_author);
}


void MessageFwdHeader::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
	from_id = Reader.ReadInt();
	}
	date = Reader.TGReadDate();
	if((Flags & (1 << 1)) != 0) 
	{
	channel_id = Reader.ReadInt();
	}
	if((Flags & (1 << 2)) != 0) 
	{
	channel_post = Reader.ReadInt();
	}
	if((Flags & (1 << 3)) != 0) 
	{
	post_author = Reader.TGReadString();
	}
	this->_Responded = true;
}
MessageFwdHeader::~MessageFwdHeader()
{
}
}//end namespace block
