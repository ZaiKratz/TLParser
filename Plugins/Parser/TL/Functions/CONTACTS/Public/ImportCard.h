#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace CONTACTS
{
class ImportCard : public TLBaseObject
{
public:
	ImportCard();
	ImportCard(TArray<int32> export_card);

	~ImportCard();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<int32>  GetExportCard() const
	{
		 return this->export_card;
	}

	COMMON::User* GetResult() const
	{
		 return this->result;
	}

private:
	TArray<int32> export_card;
	COMMON::User* result;
};
} //end namespace block
