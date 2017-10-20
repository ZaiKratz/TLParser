#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class DestroyAuthKey : public TLBaseObject
{
public:
	DestroyAuthKey();
	~DestroyAuthKey();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject* GetResult() const
	{
		 return this->result;
	}

private:
	TLBaseObject* result;
};
} //end namespace block
