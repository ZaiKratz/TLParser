#include "../Public/ChatFull.h"


//begin namespace block
namespace COMMON
{

ChatFull::ChatFull()
{
	this->_ConstructorID = 771925524;
}

ChatFull::ChatFull(int32 id, COMMON::ChatParticipants*  participants, COMMON::Photo*  chat_photo, COMMON::PeerNotifySettings*  notify_settings, TLBaseObject*  exported_invite, TArray<COMMON::BotInfo*>  bot_info)
{
	this->_ConstructorID = 771925524;
	this->id = id;
	this->participants = participants;
	this->chat_photo = chat_photo;
	this->notify_settings = notify_settings;
	this->exported_invite = exported_invite;
	this->bot_info = bot_info;
}
void ChatFull::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->id);
	this->participants->OnSend(Writer);
	this->chat_photo->OnSend(Writer);
	this->notify_settings->OnSend(Writer);
	this->exported_invite->OnSend(Writer);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->bot_info.Num());
	for(auto X : this->bot_info)
	{
	X->OnSend(Writer);
	}
}


void ChatFull::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadInt();
	participants = reinterpret_cast<COMMON::ChatParticipants* >(Reader.TGReadObject());
	chat_photo = reinterpret_cast<COMMON::Photo* >(Reader.TGReadObject());
	notify_settings = reinterpret_cast<COMMON::PeerNotifySettings* >(Reader.TGReadObject());
	exported_invite = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len23224 = Reader.ReadInt();
	for(int32 i = 0; i < Len23224; i++)
	{
	auto X = reinterpret_cast<COMMON::BotInfo*>(Reader.TGReadObject());
	bot_info.Add(X);
	}
	this->_Responded = true;
}
ChatFull::~ChatFull()
{
	if(this->participants)
	{
		delete this->participants;
	}
	if(this->chat_photo)
	{
		delete this->chat_photo;
	}
	if(this->notify_settings)
	{
		delete this->notify_settings;
	}
	if(this->exported_invite)
	{
		delete this->exported_invite;
	}
}
}//end namespace block
