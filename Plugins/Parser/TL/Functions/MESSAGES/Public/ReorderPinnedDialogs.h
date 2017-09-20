#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"

//begin namespace block
namespace MESSAGES
{
class ReorderPinnedDialogs : public TLBaseObject
{
public:
	ReorderPinnedDialogs();
	ReorderPinnedDialogs(bool force, TArray<PRIVATE::InputPeer*> order);

	~ReorderPinnedDialogs();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool force;
	 TArray<PRIVATE::InputPeer*> order;
	bool result;
};
} //end namespace block
