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
