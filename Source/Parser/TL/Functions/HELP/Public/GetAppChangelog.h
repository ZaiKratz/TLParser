#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace HELP
{
class GetAppChangelog : public TLBaseObject
{
public:
	GetAppChangelog();
	GetAppChangelog(FString prev_app_version);

	~GetAppChangelog();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString GetPrevAppVersion() const
	{
		 return this->prev_app_version;
	}

	COMMON::Updates* GetResult() const
	{
		 return this->result;
	}

private:
	FString prev_app_version;
	COMMON::Updates* result;
};
} //end namespace block
