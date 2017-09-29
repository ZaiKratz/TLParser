#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/DataJSON.h"

//begin namespace block
namespace PHONE
{
class GetCallConfig : public TLBaseObject
{
public:
	GetCallConfig();
	~GetCallConfig();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::DataJSON* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::DataJSON* result;
};
} //end namespace block
