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

	unsigned long long GetSessionId() const
	{
		 return this->session_id;
	}

	PRIVATE::DestroySessionRes* GetResult() const
	{
		 return this->result;
	}

private:
	unsigned long long session_id;
	PRIVATE::DestroySessionRes* result;
};
} //end namespace block
