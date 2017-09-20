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
private:
	COMMON::InputEncryptedChat* peer;
	 FDateTime max_date;
	bool result;
};
} //end namespace block
