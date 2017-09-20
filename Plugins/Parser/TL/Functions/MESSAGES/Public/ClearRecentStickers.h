#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class ClearRecentStickers : public TLBaseObject
{
public:
	ClearRecentStickers();
	ClearRecentStickers(bool attached);

	~ClearRecentStickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool attached;
	bool result;
};
} //end namespace block
