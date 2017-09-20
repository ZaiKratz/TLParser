#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/Messages.h"

//begin namespace block
namespace MESSAGES
{
class GetMessages : public TLBaseObject
{
public:
	GetMessages();
	GetMessages(TArray<int32> id);

	~GetMessages();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<int32> id;
	MESSAGES::Messages* result;
};
} //end namespace block
