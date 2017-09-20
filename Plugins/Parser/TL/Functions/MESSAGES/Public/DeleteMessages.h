#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/AffectedMessages.h"

//begin namespace block
namespace MESSAGES
{
class DeleteMessages : public TLBaseObject
{
public:
	DeleteMessages();
	DeleteMessages(bool revoke, TArray<int32> id);

	~DeleteMessages();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool revoke;
	 TArray<int32> id;
	MESSAGES::AffectedMessages* result;
};
} //end namespace block
