#pragma once
#include "Engine.h"
#include "../../../Types/Private/DestroySessionRes.h"

#include "../../../Types/Private/DestroySessionRes.h"

//begin namespace block
namespace COMMON
{
class DestroySessionNone : public PRIVATE::DestroySessionRes
{
public:
	DestroySessionNone();
	DestroySessionNone(unsigned long long session_id);

	~DestroySessionNone();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetSessionId() const
	{
		 return this->session_id;
	}

private:
	unsigned long long session_id;
};
} //end namespace block