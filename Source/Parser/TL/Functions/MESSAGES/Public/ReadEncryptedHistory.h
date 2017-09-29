#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputEncryptedChat.h"

//begin namespace block
namespace MESSAGES
{
class ReadEncryptedHistory : public TLBaseObject
{
public:
	ReadEncryptedHistory();
	ReadEncryptedHistory(COMMON::InputEncryptedChat* peer, FDateTime max_date);

	~ReadEncryptedHistory();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputEncryptedChat*  Getpeer() const
	{
		 return this->peer;
	}

	FDateTime GetMaxDate() const
	{
		 return this->max_date;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputEncryptedChat* peer;
	 FDateTime max_date;
	bool result;
};
} //end namespace block
