#include "../Public/Chat.h"


//begin namespace block
namespace COMMON
{

Chat::Chat()
{
	this->_ConstructorID = 1423776985;
}

Chat::Chat(bool creator, bool kicked, bool left, bool admins_enabled, bool admin, bool deactivated, int32 id, FString title, COMMON::ChatPhoto* photo, int32 participants_count, FDateTime date, int32 version, COMMON::InputChannel* migrated_to)
{
	this->_ConstructorID = 1423776985;
	this->creator = creator;
	this->kicked = kicked;
	this->left = left;
	this->admins_enabled = admins_enabled;
	this->admin = admin;
	this->deactivated = deactivated;
	this->id = id;
	this->title = title;
	this->photo = photo;
	this->participants_count = participants_count;
	this->date = date;
	this->version = version;
	this->migrated_to = migrated_to;
}
void Chat::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!creator)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!kicked)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!left)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(!admins_enabled)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(!admin)
	{
		Flags |= (1 << 4);
	}
	else
	{
		Flags |= 0;
	}
	if(!deactivated)
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	if(!migrated_to)
	{
		Flags |= (1 << 6);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->id);
	Writer.TGWriteString(this->title);
	this->photo->OnSend(Writer);
	Writer.WriteInt(this->participants_count);
	Writer.TGWriteDate(this->date);
	Writer.WriteInt(this->version);
	if(!this->migrated_to)
	{
	this->migrated_to->OnSend(Writer);
	}
}


void Chat::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		creator = true;
	}
	if((Flags & (1 << 1)) != 0) 
	{
		kicked = true;
	}
	if((Flags & (1 << 2)) != 0) 
	{
		left = true;
	}
	if((Flags & (1 << 3)) != 0) 
	{
		admins_enabled = true;
	}
	if((Flags & (1 << 4)) != 0) 
	{
		admin = true;
	}
	if((Flags & (1 << 5)) != 0) 
	{
		deactivated = true;
	}
	id = Reader.ReadInt();
	title = Reader.TGReadString();
	photo = reinterpret_cast<COMMON::ChatPhoto*>(Reader.TGReadObject());
	participants_count = Reader.ReadInt();
	date = Reader.TGReadDate();
	version = Reader.ReadInt();
	if((Flags & (1 << 6)) != 0) 
	{
	migrated_to = reinterpret_cast<COMMON::InputChannel*>(Reader.TGReadObject());
	}
}
Chat::~Chat()
{

}
}//end namespace block
