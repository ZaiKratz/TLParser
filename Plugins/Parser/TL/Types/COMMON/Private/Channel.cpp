#include "../Public/Channel.h"


//begin namespace block
namespace COMMON
{

Channel::Channel()
{
	this->_ConstructorID = 64;
}

Channel::Channel(bool creator, bool left, bool editor, bool broadcast, bool verified, bool megagroup, bool restricted, bool democracy, bool signatures, bool min, int32 id, unsigned long long access_hash, FString title, FString username, COMMON::ChatPhoto* photo, FDateTime date, int32 version, FString restriction_reason, COMMON::ChannelAdminRights* admin_rights, COMMON::ChannelBannedRights* banned_rights)
{
	this->_ConstructorID = 64;
	this->creator = creator;
	this->left = left;
	this->editor = editor;
	this->broadcast = broadcast;
	this->verified = verified;
	this->megagroup = megagroup;
	this->restricted = restricted;
	this->democracy = democracy;
	this->signatures = signatures;
	this->min = min;
	this->id = id;
	this->access_hash = access_hash;
	this->title = title;
	this->username = username;
	this->photo = photo;
	this->date = date;
	this->version = version;
	this->restriction_reason = restriction_reason;
	this->admin_rights = admin_rights;
	this->banned_rights = banned_rights;
}
void Channel::OnSend(BinaryWriter& Writer)
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
	if(!left)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(!editor)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(!broadcast)
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	if(!verified)
	{
		Flags |= (1 << 7);
	}
	else
	{
		Flags |= 0;
	}
	if(!megagroup)
	{
		Flags |= (1 << 8);
	}
	else
	{
		Flags |= 0;
	}
	if(!restricted)
	{
		Flags |= (1 << 9);
	}
	else
	{
		Flags |= 0;
	}
	if(!democracy)
	{
		Flags |= (1 << 10);
	}
	else
	{
		Flags |= 0;
	}
	if(!signatures)
	{
		Flags |= (1 << 11);
	}
	else
	{
		Flags |= 0;
	}
	if(!min)
	{
		Flags |= (1 << 12);
	}
	else
	{
		Flags |= 0;
	}
	if(!access_hash)
	{
		Flags |= (1 << 13);
	}
	else
	{
		Flags |= 0;
	}
	if(!username.IsEmpty())
	{
		Flags |= (1 << 6);
	}
	else
	{
		Flags |= 0;
	}
	if(!restriction_reason.IsEmpty())
	{
		Flags |= (1 << 9);
	}
	else
	{
		Flags |= 0;
	}
	if(!admin_rights)
	{
		Flags |= (1 << 14);
	}
	else
	{
		Flags |= 0;
	}
	if(!banned_rights)
	{
		Flags |= (1 << 15);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->id);
	if(!this->access_hash)
	{
	Writer.WriteLong(this->access_hash);
	}
	Writer.TGWriteString(this->title);
	Writer.TGWriteString(this->username);
	this->photo->OnSend(Writer);
	Writer.TGWriteDate(this->date);
	Writer.WriteInt(this->version);
	Writer.TGWriteString(this->restriction_reason);
	if(!this->admin_rights)
	{
	this->admin_rights->OnSend(Writer);
	}
	if(!this->banned_rights)
	{
	this->banned_rights->OnSend(Writer);
	}
}


void Channel::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		creator = true;
	}
	if((Flags & (1 << 2)) != 0) 
	{
		left = true;
	}
	if((Flags & (1 << 3)) != 0) 
	{
		editor = true;
	}
	if((Flags & (1 << 5)) != 0) 
	{
		broadcast = true;
	}
	if((Flags & (1 << 7)) != 0) 
	{
		verified = true;
	}
	if((Flags & (1 << 8)) != 0) 
	{
		megagroup = true;
	}
	if((Flags & (1 << 9)) != 0) 
	{
		restricted = true;
	}
	if((Flags & (1 << 10)) != 0) 
	{
		democracy = true;
	}
	if((Flags & (1 << 11)) != 0) 
	{
		signatures = true;
	}
	if((Flags & (1 << 12)) != 0) 
	{
		min = true;
	}
	id = Reader.ReadInt();
	if((Flags & (1 << 13)) != 0) 
	{
	access_hash = Reader.ReadLong();
	}
	title = Reader.TGReadString();
	if((Flags & (1 << 6)) != 0) 
	{
	username = Reader.TGReadString();
	}
	photo = reinterpret_cast<COMMON::ChatPhoto*>(Reader.TGReadObject());
	date = Reader.TGReadDate();
	version = Reader.ReadInt();
	if((Flags & (1 << 9)) != 0) 
	{
	restriction_reason = Reader.TGReadString();
	}
	if((Flags & (1 << 14)) != 0) 
	{
	admin_rights = reinterpret_cast<COMMON::ChannelAdminRights*>(Reader.TGReadObject());
	}
	if((Flags & (1 << 15)) != 0) 
	{
	banned_rights = reinterpret_cast<COMMON::ChannelBannedRights*>(Reader.TGReadObject());
	}
}
Channel::~Channel()
{

}
}//end namespace block
