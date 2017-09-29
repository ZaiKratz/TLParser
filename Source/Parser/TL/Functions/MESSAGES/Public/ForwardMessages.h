#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class ForwardMessages : public TLBaseObject
{
public:
	ForwardMessages();
	ForwardMessages(bool silent, bool background, bool with_my_score, PRIVATE::InputPeer* from_peer, TArray<int32> id, TArray<unsigned long long> random_id, PRIVATE::InputPeer* to_peer);

	~ForwardMessages();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getsilent() const
	{
		 return this->silent;
	}

	bool Getbackground() const
	{
		 return this->background;
	}

	bool GetWithMyScore() const
	{
		 return this->with_my_score;
	}

	PRIVATE::InputPeer*  GetFromPeer() const
	{
		 return this->from_peer;
	}

	TArray<int32>  Getid() const
	{
		 return this->id;
	}

	TArray<unsigned long long>  GetRandomId() const
	{
		 return this->random_id;
	}

	PRIVATE::InputPeer*  GetToPeer() const
	{
		 return this->to_peer;
	}

	COMMON::Updates* GetResult() const
	{
		 return this->result;
	}

private:
	bool silent;
	 bool background;
	 bool with_my_score;
	 PRIVATE::InputPeer* from_peer;
	 TArray<int32> id;
	 TArray<unsigned long long> random_id;
	 PRIVATE::InputPeer* to_peer;
	COMMON::Updates* result;
};
} //end namespace block
