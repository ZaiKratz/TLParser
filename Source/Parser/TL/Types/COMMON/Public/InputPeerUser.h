#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputPeer.h"

#include "../../../Types/Private/InputPeer.h"

//begin namespace block
namespace COMMON
{
class InputPeerUser : public PRIVATE::InputPeer
{
public:
	InputPeerUser();
	InputPeerUser(int32 user_id, unsigned long long access_hash);

	~InputPeerUser();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	unsigned long long GetAccessHash() const
	{
		 return this->access_hash;
	}

private:
	int32 user_id;
	 unsigned long long access_hash;
};
} //end namespace block
