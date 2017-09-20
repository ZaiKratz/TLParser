#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ContactStatus.h"

//begin namespace block
namespace CONTACTS
{
class GetStatuses : public TLBaseObject
{
public:
	GetStatuses();
	~GetStatuses();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<COMMON::ContactStatus*> result;
};
} //end namespace block
