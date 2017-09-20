#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class SentEncryptedMessage : public TLBaseObject
{
public:
	SentEncryptedMessage();
	SentEncryptedMessage(FDateTime date);

	~SentEncryptedMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FDateTime date;
};
} //end namespace block
