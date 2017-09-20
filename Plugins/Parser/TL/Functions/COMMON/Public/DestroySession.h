#pragma once
#include "Engine.h"
#include "../../../Types/Private/DestroySessionRes.h"

#include "../../../Types/Private/DestroySessionRes.h"

//begin namespace block
namespace COMMON
{
class DestroySession : public PRIVATE::DestroySessionRes
{
public:
	DestroySession();
	DestroySession(unsigned long long session_id);

	~DestroySession();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long session_id;
	PRIVATE::DestroySessionRes* result;
};
} //end namespace block
