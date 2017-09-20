#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Contacts/Public/Found.h"

//begin namespace block
namespace CONTACTS
{
class Search : public TLBaseObject
{
public:
	Search();
	Search(FString q, int32 limit);

	~Search();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString q;
	 int32 limit;
	CONTACTS::Found* result;
};
} //end namespace block
