#pragma once
#include "Engine.h"
#include "../../../Types/Private/NewSession.h"

#include "../../../Types/Private/NewSession.h"

//begin namespace block
namespace COMMON
{
class NewSessionCreated : public PRIVATE::NewSession
{
public:
	NewSessionCreated();
	NewSessionCreated(unsigned long long first_msg_id, unsigned long long unique_id, unsigned long long server_salt);

	~NewSessionCreated();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetFirstMsgId() const
	{
		 return this->first_msg_id;
	}

	unsigned long long GetUniqueId() const
	{
		 return this->unique_id;
	}

	unsigned long long GetServerSalt() const
	{
		 return this->server_salt;
	}

private:
	unsigned long long first_msg_id;
	 unsigned long long unique_id;
	 unsigned long long server_salt;
};
} //end namespace block
