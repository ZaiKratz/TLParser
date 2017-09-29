#pragma once
#include "Engine.h"
#include "../../../Types/Private/DestroyAuthKeyRes.h"

#include "../../../Types/Private/DestroyAuthKeyRes.h"

//begin namespace block
namespace COMMON
{
class DestroyAuthKey : public PRIVATE::DestroyAuthKeyRes
{
public:
	DestroyAuthKey();
	~DestroyAuthKey();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::DestroyAuthKeyRes* GetResult() const
	{
		 return this->result;
	}

private:
	PRIVATE::DestroyAuthKeyRes* result;
};
} //end namespace block
