#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class SetGameScore : public TLBaseObject
{
public:
	SetGameScore();
	SetGameScore(bool edit_message, bool force, PRIVATE::InputPeer* peer, int32 id, COMMON::InputUser* user_id, int32 score);

	~SetGameScore();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool edit_message;
	 bool force;
	 PRIVATE::InputPeer* peer;
	 int32 id;
	 COMMON::InputUser* user_id;
	 int32 score;
	COMMON::Updates* result;
};
} //end namespace block
