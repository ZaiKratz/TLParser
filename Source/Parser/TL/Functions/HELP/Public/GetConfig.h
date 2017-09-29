#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Config.h"

//begin namespace block
namespace HELP
{
class GetConfig : public TLBaseObject
{
public:
	GetConfig();
	~GetConfig();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::Config* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::Config* result;
};
} //end namespace block
