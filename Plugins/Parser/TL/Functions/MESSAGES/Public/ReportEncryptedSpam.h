#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputEncryptedChat.h"

//begin namespace block
namespace MESSAGES
{
class ReportEncryptedSpam : public TLBaseObject
{
public:
	ReportEncryptedSpam();
	ReportEncryptedSpam(COMMON::InputEncryptedChat* peer);

	~ReportEncryptedSpam();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputEncryptedChat* peer;
	bool result;
};
} //end namespace block
