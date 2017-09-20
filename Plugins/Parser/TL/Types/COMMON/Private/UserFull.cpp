#include "../Public/UserFull.h"


//begin namespace block
namespace COMMON
{

UserFull::UserFull()
{
	this->_ConstructorID = 64;
}

UserFull::UserFull(bool blocked, bool phone_calls_available, bool phone_calls_private, COMMON::User* user, FString about, CONTACTS::Link* link, COMMON::Photo* profile_photo, COMMON::PeerNotifySettings* notify_settings, COMMON::BotInfo* bot_info, int32 common_chats_count)
{
	this->_ConstructorID = 64;
	this->blocked = blocked;
	this->phone_calls_available = phone_calls_available;
	this->phone_calls_private = phone_calls_private;
	this->user = user;
	this->about = about;
	this->link = link;
	this->profile_photo = profile_photo;
	this->notify_settings = notify_settings;
	this->bot_info = bot_info;
	this->common_chats_count = common_chats_count;
}
void UserFull::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!blocked)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!phone_calls_available)
	{
		Flags |= (1 << 4);
	}
	else
	{
		Flags |= 0;
	}
	if(!phone_calls_private)
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	if(!about.IsEmpty())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!profile_photo)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(!bot_info)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->user->OnSend(Writer);
	Writer.TGWriteString(this->about);
	this->link->OnSend(Writer);
	if(!this->profile_photo)
	{
	this->profile_photo->OnSend(Writer);
	}
	this->notify_settings->OnSend(Writer);
	if(!this->bot_info)
	{
	this->bot_info->OnSend(Writer);
	}
	Writer.WriteInt(this->common_chats_count);
}


void UserFull::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		blocked = true;
	}
	if((Flags & (1 << 4)) != 0) 
	{
		phone_calls_available = true;
	}
	if((Flags & (1 << 5)) != 0) 
	{
		phone_calls_private = true;
	}
	user = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	if((Flags & (1 << 1)) != 0) 
	{
	about = Reader.TGReadString();
	}
	link = reinterpret_cast<CONTACTS::Link*>(Reader.TGReadObject());
	if((Flags & (1 << 2)) != 0) 
	{
	profile_photo = reinterpret_cast<COMMON::Photo*>(Reader.TGReadObject());
	}
	notify_settings = reinterpret_cast<COMMON::PeerNotifySettings*>(Reader.TGReadObject());
	if((Flags & (1 << 3)) != 0) 
	{
	bot_info = reinterpret_cast<COMMON::BotInfo*>(Reader.TGReadObject());
	}
	common_chats_count = Reader.ReadInt();
}
UserFull::~UserFull()
{

}
}//end namespace block
