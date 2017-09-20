#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace AUTH
{
class ResetAuthorizations : public TLBaseObject
{
public:
	ResetAuthorizations();
	~ResetAuthorizations();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool result;
};
} //end namespace block
