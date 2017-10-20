#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/DcOption.h"

//begin namespace block
namespace COMMON
{
class UpdateDcOptions : public TLBaseObject
{
public:
	UpdateDcOptions();
	UpdateDcOptions(TArray<COMMON::DcOption*> dc_options);

	~UpdateDcOptions();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<COMMON::DcOption*>  GetDcOptions() const
	{
		 return this->dc_options;
	}

private:
	TArray<COMMON::DcOption*> dc_options;
};
} //end namespace block
