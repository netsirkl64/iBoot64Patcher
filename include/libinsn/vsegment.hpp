//
//  vsegment.hpp
//  liboffsetfinder64
//
//  Created by tihmstar on 28.09.19.
//  Copyright © 2019 tihmstar. All rights reserved.
//

#ifndef vsegment_hpp
#define vsegment_hpp

#include <stdio.h>
#include <libinsn/insn.hpp>
#include <iostream>

namespace tihmstar{
    namespace libinsn{
        class vsegment{
        public:
            enum vmprot{
                kVMPROTNONE  = 0,
                kVMPROTREAD  = 1 << 0,
                kVMPROTWRITE = 1 << 1,
                kVMPROTEXEC  = 1 << 2,
            };
        private:
            int _perms;
            const uint8_t *_buf; //noalloc
            size_t _size;
            loc_t _vaddr;
            offset_t _curpos;
            std::string _segname;

        public:
            vsegment(const void *buf, size_t size, loc_t vmemAddr, int perms, std::string segname = "");
            vsegment(const vsegment &cpy); //copy constructor
            vsegment(const vsegment &cpy, loc_t pos); //copy constructor

            
            bool isInRange(loc_t p);
            loc_t memmem(const void *little, size_t little_len, loc_t startLoc = 0);
            
            //iterator operator
            insn operator+(int i);
            insn operator-(int i);
            insn operator++();
            insn operator--();
            vsegment &operator+=(int i);
            vsegment &operator-=(int i);
            vsegment &operator=(loc_t p);
            
            //segment info functions
            loc_t base() const {return _vaddr;}
            size_t size() const {return _size;}
            int perm() const {return _perms;}
            std::string segname() {return _segname;}
            const void *memoryForLoc(loc_t loc);

            //deref operator
            uint64_t pc() const;
            uint32_t value(loc_t p) const; //arbitrary pos
            uint64_t doublevalue(loc_t p) const; //arbitrary pos
            uint32_t value() const; //curpos
            uint64_t doublevalue() const; //curpos

            //insn operator
            insn getinsn();
            insn operator()();
            operator loc_t() const;
        };
    };
};

#endif /* vsegment_hpp */
