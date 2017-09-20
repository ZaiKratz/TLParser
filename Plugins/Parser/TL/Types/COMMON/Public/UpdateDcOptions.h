#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Common/Public/DcOption.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateDcOptions : public PRIVATE::Update
{
public:
	UpdateDcOptions();
	UpdateDcOptions(TArray<COMMON::DcOption*> dc_options);

	~UpdateDcOptions();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<COMMON::DcOption*> dc_options;
};
} //end namespace block
