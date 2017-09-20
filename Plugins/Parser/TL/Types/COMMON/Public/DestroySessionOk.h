#pragma once
#include "Engine.h"
#include "../../../Types/Private/DestroySessionRes.h"

#include "../../../Types/Private/DestroySessionRes.h"

//begin namespace block
namespace COMMON
{
class DestroySessionOk : public PRIVATE::DestroySessionRes
{
public:
	DestroySessionOk();
	DestroySessionOk(unsigned long long session_id);

	~DestroySessionOk();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long session_id;
};
} //end namespace block
