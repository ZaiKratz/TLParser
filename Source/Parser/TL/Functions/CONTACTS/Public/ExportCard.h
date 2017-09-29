#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace CONTACTS
{
class ExportCard : public TLBaseObject
{
public:
	ExportCard();
	~ExportCard();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<int32> GetResult() const
	{
		 return this->result;
	}

private:
	TArray<int32> result;
};
} //end namespace block
