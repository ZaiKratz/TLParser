#include "../Public/ChannelBannedRights.h"


//begin namespace block
namespace COMMON
{

ChannelBannedRights::ChannelBannedRights()
{
	this->_ConstructorID = 1229115224;
}

ChannelBannedRights::ChannelBannedRights(bool view_messages, bool send_messages, bool send_media, bool send_stickers, bool send_gifs, bool send_games, bool send_inline, bool embed_links, FDateTime until_date)
{
	this->_ConstructorID = 1229115224;
	this->view_messages = view_messages;
	this->send_messages = send_messages;
	this->send_media = send_media;
	this->send_stickers = send_stickers;
	this->send_gifs = send_gifs;
	this->send_games = send_games;
	this->send_inline = send_inline;
	this->embed_links = embed_links;
	this->until_date = until_date;
}
void ChannelBannedRights::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!view_messages)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!send_messages)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!send_media)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(!send_stickers)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(!send_gifs)
	{
		Flags |= (1 << 4);
	}
	else
	{
		Flags |= 0;
	}
	if(!send_games)
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	if(!send_inline)
	{
		Flags |= (1 << 6);
	}
	else
	{
		Flags |= 0;
	}
	if(!embed_links)
	{
		Flags |= (1 << 7);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteDate(this->until_date);
}


void ChannelBannedRights::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		view_messages = true;
	}
	if((Flags & (1 << 1)) != 0) 
	{
		send_messages = true;
	}
	if((Flags & (1 << 2)) != 0) 
	{
		send_media = true;
	}
	if((Flags & (1 << 3)) != 0) 
	{
		send_stickers = true;
	}
	if((Flags & (1 << 4)) != 0) 
	{
		send_gifs = true;
	}
	if((Flags & (1 << 5)) != 0) 
	{
		send_games = true;
	}
	if((Flags & (1 << 6)) != 0) 
	{
		send_inline = true;
	}
	if((Flags & (1 << 7)) != 0) 
	{
		embed_links = true;
	}
	until_date = Reader.TGReadDate();
}
ChannelBannedRights::~ChannelBannedRights()
{

}
}//end namespace block
