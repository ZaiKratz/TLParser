#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class GetAllDrafts : public TLBaseObject
{
public:
	GetAllDrafts();
	~GetAllDrafts();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::Updates* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::Updates* result;
};
} //end namespace block
