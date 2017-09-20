#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/AffectedMessages.h"

//begin namespace block
namespace MESSAGES
{
class ReadMessageContents : public TLBaseObject
{
public:
	ReadMessageContents();
	ReadMessageContents(TArray<int32> id);

	~ReadMessageContents();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<int32> id;
	MESSAGES::AffectedMessages* result;
};
} //end namespace block
