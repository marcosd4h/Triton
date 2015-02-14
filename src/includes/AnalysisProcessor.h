#ifndef _ANALYSISPROCESSOR_H_
#define _ANALYSISPROCESSOR_H_

#include "SymbolicEngine.h"
#include "TaintEngine.h"


class AnalysisProcessor {
  public:
    AnalysisProcessor();

    // Symbolic Engine Facade
    // ----------------------

    // Returns a symbolic element for the register (regID).
    SymbolicElement *createRegSE(std::stringstream &expr, uint64_t regID);

    // Returns a symbolic element for the memory address.
    SymbolicElement *createMemSE(std::stringstream &expr, uint64_t address);

    // Returns the ID of the symbolic element currently present in the
    // symbolic register. If there is no symbolic element, it returns UNSET.
    uint64_t getRegSymbolicID(uint64_t regID);

    // Returns the ID of the symbolic element currently present in the
    // symbolic memory. If there is no symbolic element, it returns UNSET.
    uint64_t getMemorySymbolicID(uint64_t address);

    // Returns the symbolic engine reference
    SymbolicEngine &getSymbolicEngine();

    // Taint Engine Facade
    // -------------------

    // Returns the taint engine reference
    TaintEngine &getTaintEngine();

    // Taint interface.
    // Taint the symbolic element if the taint occurs.
    void spreadTaintRegReg(SymbolicElement *se, uint64_t regDst, uint64_t regSrc);
    void spreadTaintRegImm(SymbolicElement *se, uint64_t regDst);
    void spreadTaintRegMem(SymbolicElement *se, uint64_t regDst, uint64_t memSrc, uint32_t readSize);
    void spreadTaintMemImm(SymbolicElement *se, uint64_t memDst);
    void spreadTaintMemReg(SymbolicElement *se, uint64_t memDst, uint64_t regSrc);


  private:
    SymbolicEngine  symEngine;
    TaintEngine     taintEngine;
};

#endif //_ANALYSISPROCESSOR_H_