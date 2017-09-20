#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Document.h"

//begin namespace block
namespace COMMON
{
class DocumentEmpty : public TLBaseObject
{
public:
	DocumentEmpty();
	DocumentEmpty(unsigned long long id);

	~DocumentEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long id;
};
} //end namespace block
