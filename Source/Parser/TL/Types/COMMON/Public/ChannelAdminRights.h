#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminRights : public TLBaseObject
{
public:
	ChannelAdminRights();
	ChannelAdminRights(bool change_info, bool post_messages, bool edit_messages, bool delete_messages, bool ban_users, bool invite_users, bool invite_link, bool pin_messages, bool add_admins);

	~ChannelAdminRights();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetChangeInfo() const
	{
		 return this->change_info;
	}

	bool GetPostMessages() const
	{
		 return this->post_messages;
	}

	bool GetEditMessages() const
	{
		 return this->edit_messages;
	}

	bool GetDeleteMessages() const
	{
		 return this->delete_messages;
	}

	bool GetBanUsers() const
	{
		 return this->ban_users;
	}

	bool GetInviteUsers() const
	{
		 return this->invite_users;
	}

	bool GetInviteLink() const
	{
		 return this->invite_link;
	}

	bool GetPinMessages() const
	{
		 return this->pin_messages;
	}

	bool GetAddAdmins() const
	{
		 return this->add_admins;
	}

private:
	bool change_info;
	 bool post_messages;
	 bool edit_messages;
	 bool delete_messages;
	 bool ban_users;
	 bool invite_users;
	 bool invite_link;
	 bool pin_messages;
	 bool add_admins;
};
} //end namespace block
