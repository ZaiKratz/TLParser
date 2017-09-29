#include "../Public/User.h"


//begin namespace block
namespace COMMON
{

User::User()
{
	this->_ConstructorID = 773059779;
}

User::User(bool self, bool contact, bool mutual_contact, bool deleted, bool bot, bool bot_chat_history, bool bot_nochats, bool verified, bool restricted, bool min, bool bot_inline_geo, int32 id, unsigned long long access_hash, FString first_name, FString last_name, FString username, FString phone, COMMON::UserProfilePhoto*  photo, PRIVATE::UserStatus*  status, int32 bot_info_version, FString restriction_reason, FString bot_inline_placeholder, FString lang_code)
{
	this->_ConstructorID = 773059779;
	this->self = self;
	this->contact = contact;
	this->mutual_contact = mutual_contact;
	this->deleted = deleted;
	this->bot = bot;
	this->bot_chat_history = bot_chat_history;
	this->bot_nochats = bot_nochats;
	this->verified = verified;
	this->restricted = restricted;
	this->min = min;
	this->bot_inline_geo = bot_inline_geo;
	this->id = id;
	this->access_hash = access_hash;
	this->first_name = first_name;
	this->last_name = last_name;
	this->username = username;
	this->phone = phone;
	this->photo = photo;
	this->status = status;
	this->bot_info_version = bot_info_version;
	this->restriction_reason = restriction_reason;
	this->bot_inline_placeholder = bot_inline_placeholder;
	this->lang_code = lang_code;
}
void User::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(self)
	{
		Flags |= (1 << 10);
	}
	else
	{
		Flags |= 0;
	}
	if(contact)
	{
		Flags |= (1 << 11);
	}
	else
	{
		Flags |= 0;
	}
	if(mutual_contact)
	{
		Flags |= (1 << 12);
	}
	else
	{
		Flags |= 0;
	}
	if(deleted)
	{
		Flags |= (1 << 13);
	}
	else
	{
		Flags |= 0;
	}
	if(bot)
	{
		Flags |= (1 << 14);
	}
	else
	{
		Flags |= 0;
	}
	if(bot_chat_history)
	{
		Flags |= (1 << 15);
	}
	else
	{
		Flags |= 0;
	}
	if(bot_nochats)
	{
		Flags |= (1 << 16);
	}
	else
	{
		Flags |= 0;
	}
	if(verified)
	{
		Flags |= (1 << 17);
	}
	else
	{
		Flags |= 0;
	}
	if(restricted)
	{
		Flags |= (1 << 18);
	}
	else
	{
		Flags |= 0;
	}
	if(min)
	{
		Flags |= (1 << 20);
	}
	else
	{
		Flags |= 0;
	}
	if(bot_inline_geo)
	{
		Flags |= (1 << 21);
	}
	else
	{
		Flags |= 0;
	}
	if(access_hash)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!first_name.IsEmpty())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!last_name.IsEmpty())
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(!username.IsEmpty())
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(!phone.IsEmpty())
	{
		Flags |= (1 << 4);
	}
	else
	{
		Flags |= 0;
	}
	if(photo)
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	if(status)
	{
		Flags |= (1 << 6);
	}
	else
	{
		Flags |= 0;
	}
	if(bot_info_version)
	{
		Flags |= (1 << 14);
	}
	else
	{
		Flags |= 0;
	}
	if(!restriction_reason.IsEmpty())
	{
		Flags |= (1 << 18);
	}
	else
	{
		Flags |= 0;
	}
	if(!bot_inline_placeholder.IsEmpty())
	{
		Flags |= (1 << 19);
	}
	else
	{
		Flags |= 0;
	}
	if(!lang_code.IsEmpty())
	{
		Flags |= (1 << 22);
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
	Writer.TGWriteString(this->first_name);
	Writer.TGWriteString(this->last_name);
	Writer.TGWriteString(this->username);
	Writer.TGWriteString(this->phone);
	if(!this->photo)
	{
	this->photo->OnSend(Writer);
	}
	if(!this->status)
	{
	this->status->OnSend(Writer);
	}
	if(!this->bot_info_version)
	{
	Writer.WriteInt(this->bot_info_version);
	}
	Writer.TGWriteString(this->restriction_reason);
	Writer.TGWriteString(this->bot_inline_placeholder);
	Writer.TGWriteString(this->lang_code);
}


void User::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 10)) != 0) 
	{
		self = true;
	}
	if((Flags & (1 << 11)) != 0) 
	{
		contact = true;
	}
	if((Flags & (1 << 12)) != 0) 
	{
		mutual_contact = true;
	}
	if((Flags & (1 << 13)) != 0) 
	{
		deleted = true;
	}
	if((Flags & (1 << 14)) != 0) 
	{
		bot = true;
	}
	if((Flags & (1 << 15)) != 0) 
	{
		bot_chat_history = true;
	}
	if((Flags & (1 << 16)) != 0) 
	{
		bot_nochats = true;
	}
	if((Flags & (1 << 17)) != 0) 
	{
		verified = true;
	}
	if((Flags & (1 << 18)) != 0) 
	{
		restricted = true;
	}
	if((Flags & (1 << 20)) != 0) 
	{
		min = true;
	}
	if((Flags & (1 << 21)) != 0) 
	{
		bot_inline_geo = true;
	}
	id = Reader.ReadInt();
	if((Flags & (1 << 0)) != 0) 
	{
	access_hash = Reader.ReadLong();
	}
	if((Flags & (1 << 1)) != 0) 
	{
	first_name = Reader.TGReadString();
	}
	if((Flags & (1 << 2)) != 0) 
	{
	last_name = Reader.TGReadString();
	}
	if((Flags & (1 << 3)) != 0) 
	{
	username = Reader.TGReadString();
	}
	if((Flags & (1 << 4)) != 0) 
	{
	phone = Reader.TGReadString();
	}
	if((Flags & (1 << 5)) != 0) 
	{
	photo = reinterpret_cast<COMMON::UserProfilePhoto* >(Reader.TGReadObject());
	}
	if((Flags & (1 << 6)) != 0) 
	{
	status = reinterpret_cast<PRIVATE::UserStatus* >(Reader.TGReadObject());
	}
	if((Flags & (1 << 14)) != 0) 
	{
	bot_info_version = Reader.ReadInt();
	}
	if((Flags & (1 << 18)) != 0) 
	{
	restriction_reason = Reader.TGReadString();
	}
	if((Flags & (1 << 19)) != 0) 
	{
	bot_inline_placeholder = Reader.TGReadString();
	}
	if((Flags & (1 << 22)) != 0) 
	{
	lang_code = Reader.TGReadString();
	}
	this->_Responded = true;
}
User::~User()
{

}
}//end namespace block
