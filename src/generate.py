from json import dump, loads
cache = "../data/cache.json"

def main():
    func()
    pass


def store(term):
    with open(cache, "a") as previous_terms:
        dump(term, previous_terms, indent=4)

def check(term):
    with open(cache) as existing_terms:
        existing_terms = loads(existing_terms)


def func():
    entries = list()

    common_terms = {
        "01": [
            "API","Agile","Algorithm","Artificial Intelligence","Automation","Big Data","Binary","Blockchain","Cloud Computing","Compiler","Container","Continuous Integration","Data Science","Data Mining","Database","Deep Learning","Deployment","DevOps","Docker","Encryption"
        ],

        "02": [
            "Endpoint","Framework","Front-End","Full Stack","Git","GitHub","Graphics Processing Unit (GPU)","Internet of Things (IoT)","Java","JavaScript","JSON","Kernel","Machine Learning","Microservices","Node.js","Open Source","Protocol","Python","Query","React"
        ],

        "03": [
            "Relational Database","Responsive Design","Serverless","Software as a Service (SaaS)","SQL","Virtual Machine (VM)","Version Control","Web Development","Web Services","Wireless","XML","Zero-Day","Agile Development","Cloud Storage","Data Lake","Data Warehouse","Edge Computing","Firewall","GraphQL","Hashing","Hypervisor"
        ],

        "04": [
            "Load Balancer","Message Queue","Microcontroller","Neural Network","NoSQL","OAuth","ORM","Packet Switching","Pipeline","Platform as a Service (PaaS)","Proxy","Public Key Infrastructure (PKI)","Refactoring","Robotics","Scalability","Script","SDK","SEO","Server-Side","Software Development Kit"
        ],

        "05": [
            "Structured Query Language","Test Automation","Unit Testing","User Interface","User Experience","Virtualization","WebSocket","Wi-Fi","Wireless Access Point","XML Schema","YAML","Versioning","Artificial Neural Network (ANN)","Back-End","Bit","Bootstrap","Cloud Native","Cloud Security","Codebase","Continuous Deployment","Containerization"

        ],

        "06": [
            "Data Modeling","Data Synchronization","Data Validation","Database Management System (DBMS)","Distributed System","ETL (Extract, Transform, Load)","Firmware","Functional Programming","Graph Database","Hardware as a Service (HaaS)","Hyperledger","Internet Protocol (IP)","Key Performance Indicator (KPI)","Latency","Load Testing","Machine Vision","Microservice Architecture","Middleware","Model-View-Controller (MVC)","Natural Language Processing (NLP)","Object-Oriented Programming (OOP)"
        ],

        "07": [
            "Pair Programming","Penetration Testing","Progressive Web App (PWA)","Public Cloud","Quality Assurance (QA)","Queue","React Native","Regression Testing","Relational Model","Server Architecture","Software Engineering","Software Lifecycle","Software Project Management","Software Testing","Software Versioning","SQL Injection","Stateful","StatefulSet","Server Cluster","Server Farm"
        ],

        "08": [
            "Server-Side Rendering (SSR)","Static Analysis","Technical Debt","Tokenization","Unit Test","User Authentication","User Authorization","Virtual Private Network (VPN)","Web API","Web Assembly (WASM)","Web Scraping","WebSocket API","Wireframe","World Wide Web (WWW)","XaaS","Zero Trust","Zip File","Agile Methodology","Artificial Intelligence (AI)","Big O Notation","Bitrate"
        ],

        "09": [
            "Blockchain Technology","Bytecode","Canonical URL","CI/CD","Cloud Infrastructure","Container Orchestration","Data Encryption","Data Governance","Data Lakehouse","Data Loss Prevention","Data Privacy","Data Redundancy","Database Sharding","Deep Reinforcement Learning","Design Patterns","Distributed Ledger","Domain Name System (DNS)","Edge Computing","Elasticity","Event-Driven Architecture"
        ],

        "10": [
            "Feature Flagging","Function as a Service (FaaS)","Fuzzy Logic","Graph Theory","Hyperparameter","Incremental Backup","Incremental Search","Information Retrieval","Intent-Based Networking","Intelligent Automation","JSON Web Token (JWT)","Keycloak","Latency Sensitive Network (LSN)","Load Balancing","Machine Learning Operations (MLOps)","Micro-frontend","Microkernel Architecture","Model-View-ViewModel (MVVM)","Network Function Virtualization (NFV)","NoSQL Database"
        ],

        "11": [
            "OAuth 2.0","OpenAPI Specification","OpenStack","Orchestration","Parallel Computing","Peer-to-Peer (P2P)","Platform Engineering","Point of Sale (POS)","Predictive Analytics","Private Cloud","Quantum Computing","Real-Time Data","Redundancy","RESTful API","Robotic Process Automation (RPA)","Secure Sockets Layer (SSL)","Serverless Computing","Service-Oriented Architecture (SOA)","Single Page Application (SPA)","Site Reliability Engineering (SRE)"
        ],

        "12": [
            "Smart Contracts","Software as a Service (SaaS)","Software Defined Networking (SDN)","Soldering","Static Site Generator (SSG)","Synthetic Monitoring","Test-Driven Development (TDD)","Threat Intelligence","Tokenomics","UI/UX Design","User-Centered Design","Virtual Private Cloud (VPC)","Virtual Reality (VR)","Web Development Framework","Webhooks","Wireless Fidelity (Wi-Fi)","Xamarin","Zero-Knowledge Proofs"
        ],        
    }
    for term in common_terms["01"]:
        response_data = Agent().getCompletion(term)
        data = loads(response_data)
        entries.append(data)
    
    with open("../data/common.json", "a") as file:
        dump(entries, file, indent=4)


if __name__ == "__main__":
    main()