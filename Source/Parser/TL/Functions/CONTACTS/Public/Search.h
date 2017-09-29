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

	FString Getq() const
	{
		 return this->q;
	}

	int32 Getlimit() const
	{
		 return this->limit;
	}

	CONTACTS::Found* GetResult() const
	{
		 return this->result;
	}

private:
	FString q;
	 int32 limit;
	CONTACTS::Found* result;
};
} //end namespace block
