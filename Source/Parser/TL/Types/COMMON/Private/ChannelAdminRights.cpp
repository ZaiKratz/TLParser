#include "../Public/ChannelAdminRights.h"


//begin namespace block
namespace COMMON
{

ChannelAdminRights::ChannelAdminRights()
{
	this->_ConstructorID = 1568467877;
}

ChannelAdminRights::ChannelAdminRights(bool change_info, bool post_messages, bool edit_messages, bool delete_messages, bool ban_users, bool invite_users, bool invite_link, bool pin_messages, bool add_admins)
{
	this->_ConstructorID = 1568467877;
	this->change_info = change_info;
	this->post_messages = post_messages;
	this->edit_messages = edit_messages;
	this->delete_messages = delete_messages;
	this->ban_users = ban_users;
	this->invite_users = invite_users;
	this->invite_link = invite_link;
	this->pin_messages = pin_messages;
	this->add_admins = add_admins;
}
void ChannelAdminRights::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(change_info)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(post_messages)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(edit_messages)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(delete_messages)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(ban_users)
	{
		Flags |= (1 << 4);
	}
	else
	{
		Flags |= 0;
	}
	if(invite_users)
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	if(invite_link)
	{
		Flags |= (1 << 6);
	}
	else
	{
		Flags |= 0;
	}
	if(pin_messages)
	{
		Flags |= (1 << 7);
	}
	else
	{
		Flags |= 0;
	}
	if(add_admins)
	{
		Flags |= (1 << 9);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

}


void ChannelAdminRights::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		change_info = true;
	}
	if((Flags & (1 << 1)) != 0) 
	{
		post_messages = true;
	}
	if((Flags & (1 << 2)) != 0) 
	{
		edit_messages = true;
	}
	if((Flags & (1 << 3)) != 0) 
	{
		delete_messages = true;
	}
	if((Flags & (1 << 4)) != 0) 
	{
		ban_users = true;
	}
	if((Flags & (1 << 5)) != 0) 
	{
		invite_users = true;
	}
	if((Flags & (1 << 6)) != 0) 
	{
		invite_link = true;
	}
	if((Flags & (1 << 7)) != 0) 
	{
		pin_messages = true;
	}
	if((Flags & (1 << 9)) != 0) 
	{
		add_admins = true;
	}
	this->_Responded = true;
}
ChannelAdminRights::~ChannelAdminRights()
{

}
}//end namespace block
